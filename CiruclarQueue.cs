using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SparklingWater
{
    enum item
    {
        Berry1,
        Berry2,
        Berry3,
        Berry4,
        Water1,
        Water2,
        Water3,
        Water4,
        Citrus1,
        Citrus2,
        Citrus3,
        Citrus4,
        Cocunut
    }

    
    class CiruclarQueue
    {
        public int length;
        public item[] it=new item[13];

        public CiruclarQueue(int len,item[] tmp)
        {
            length = len;
            
            for (int i = 0; i < length; i++)
            {
                it[i] = tmp[i];
            }
        }

        public int findCocunut()
        {
            for (int i = 0; i < length; i++)
            {
                if (it[i] == item.Cocunut)
                {
                    return i;
                }
            }
            return -1;
        }

        public void FinalDistribution()
        {
            int index=findCocunut()+1;


            Console.WriteLine("Coconut is in "+index+" place so will start ");
            Console.WriteLine(" Final Fair distribution is ...\n");

            for (int i = 0; i < length; i++)
            {
                if (index >= length)
                {
                    index = 0;
                }

                Console.WriteLine((i+1) + "  " + it[index]);
                index++;
            }
        }
    }
}
