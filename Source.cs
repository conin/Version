using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SparklingWater
{
    class Source
    {
        static void Main(string[] args)
        {
            item[] it = new item[13] { item.Berry1, item.Berry2, item.Berry3, item.Berry4,
                                       item.Citrus1, item.Citrus2, item.Citrus3,item.Cocunut,
                                       item.Citrus4, item.Water1, item.Water2, item.Water3, item.Water4};
            

            CiruclarQueue cq = new CiruclarQueue(13,it);
            cq.FinalDistribution();
        }
    }
}
