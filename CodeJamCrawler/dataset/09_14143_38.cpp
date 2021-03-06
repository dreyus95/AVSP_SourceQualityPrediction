//Solution to A for Code Jam qualification round 1C 2009
//By Dmitry Kamenetsky

import java.io.*;
import java.util.*;

public class A
{
	static int T;
	public static void main(String[] args) throws Exception
	{
	   // String a="abc";
	    //long a2=Long.parseLong(a,16);
	  //  System.out.println(a2);
	
		RandomAccessFile in = new RandomAccessFile(args[0],"r");
		T=Integer.parseInt(in.readLine());


		for (int i=1; i<=T; i++)
		{
            String line=in.readLine();
            String ans=solve(line);
            System.out.println("Case #"+i+": "+ans);
        }

		in.close();
	}

	public static String solve(String line)
    {
//        System.out.println(count);

        boolean[] used=new boolean[line.length()];
        StringBuffer b=new StringBuffer(line);
        int count=1;
        int max=2;
        for (int i=0; i<b.length(); i++)
        {
            if (used[i]) continue;
            for (int k=0; k<b.length(); k++)
            {
                if (used[k] || line.charAt(k)!=line.charAt(i)) continue;
                if (count==1) b.setCharAt(k,'1');
                else if (count==2) b.setCharAt(k,'0');
                else if (count<=10) b.setCharAt(k,(char)('0'+count-1));
                else b.setCharAt(k,(char)('a'+count-11));
                used[k]=true;
                max=Math.max(max,count);
            }
            count++;
        }
     //   System.out.println(b+" "+max);
        
        long ans=Long.parseLong(""+b,max);
     /*   for (int i=max; i<=36; i++)
        {
            long ans2=Long.parseLong(""+b,i);
            if (ans2<ans)
            {
                System.out.println("wow "+b);
                System.exit(0);
            }
        }*/


        return ""+ans;
	}
}