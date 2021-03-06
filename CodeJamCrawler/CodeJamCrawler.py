from bs4 import BeautifulSoup
import zipfile
import os
import time
import threading
import random

def getRandom():
	return random.uniform(0.001, 0.2)

import urllib

parser = 'html.parser'
id_counter=0

def process_body(soup, year, contestant_name):
    body = BeautifulSoup(str(soup.body), 'html.parser')
    content = BeautifulSoup(str(body.find_all('div', id='content')[0]), 'html.parser')
    # get display block
    display = BeautifulSoup(str(content.find_all('div')[1]), 'html.parser')
    tables = display.find_all('table', class_='stats')
    for tab in tables:
        table = BeautifulSoup(str(tab), 'html.parser')
        round = BeautifulSoup(str(table.find('caption')), 'html.parser')
        score = BeautifulSoup(str(round.find('span')), 'html.parser').string.split(' ')[0]
        table_body = table.findAll('tr')
        code_links = table_body[2].find_all('a')
        
        for link in code_links:
            #print link.get('href')
            global id_counter
            path_to_zip = 'dataset_with_coder_id/' + str(id_counter) + '_' + score + '.zip'
            success = False
            for alive_count in range(3):
                try:
                    urllib.urlretrieve(link.get('href'), path_to_zip)
                    success = True
                except IOError as e:
                    print "error reading"
                    # give him some time to recover
                    time.sleep(getRandom())
            if not success:
                continue
            zip_ref = zipfile.ZipFile(path_to_zip, 'r')
            #print path_to_file
            for file_name in zip_ref.namelist():
              	tokens = file_name.split('.')
              	extension = tokens[len(tokens)-1]
              	if extension != 'cc' \
              		and extension != 'cxx' \
              		and extension != 'c++' \
              		and extension != 'cpp' \
              		and extension != 'c' \
              		and extension != 'C':
					print 'passing', file_name, 'with extension', extension
					continue
                path_to_file = 'dataset_with_coder_id/' + contestant_name + '_' + year + '_' + str(id_counter) + '_' + score + '.' + extension
                output = open(path_to_file, 'w')
                id_counter += 1
                output.write(zip_ref.read(file_name))
            zip_ref.close()

            os.remove(path_to_zip)
        time.sleep(getRandom())

def process_contestant(url, year, contestant_name):

    page = None

    for alive_count in range(2):
        try:
            page = urllib.urlopen(url).read()
        except IOError as e:
            print "error reading"
            # give him some time to recover
            time.sleep(getRandom())

    if page == None:
        return

    soup = BeautifulSoup(page, 'html.parser')
    process_body(soup, year, contestant_name)

def process_contest(year, lines):
    for i in range(0, len(lines)):
        #print lines[i]
        url = "https://www.go-hero.net/jam/" + year + "/name/" + lines[i]
        try:
            process_contestant(url, year, lines[i])
        except IndexError as e:
            continue

def main():
    print os.getcwd()
    with open('users.txt', 'r') as file:
        lines = file.readlines()

        threads = []

        years = ["08", "09", "10", "11", "12", "13", "14"]
        for year in years:
            t = threading.Thread(target=process_contest, args=(year, lines))
            t.daemon = True
            t.start()
            threads.append(t)
            print "created thread for year", year
            #process_contest(year, lines)

        for index in range(len(threads)):
            threads[index].join()

if __name__ == '__main__':
    main()
