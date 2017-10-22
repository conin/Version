using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Maps
{
    class Source
    {
        static void Main(string[] args)
        {
            //2017-01-01; Coffee Shop; L2, L5, L5, R5, L2      ------      (R5,R10)
            //2017-01-02; Advertising Agency; R3, R3, R3, L2   ------      (R0,R5)

            //(+ve, -ve) == (3,-2)
            //2017-01-01; Coffee Shop; L1, L1, R1, L1, R1, L1, L1 ----      (L2,R3)

            //(-ve, +ve) == (-3,2)
            //2017-01-01; Coffee Shop; L1, R1, R1, L1, R1, L1, R1 -------   (R2,L3)

            //(-ve, -ve) == (-3,-2)
            //2017-01-01; Coffee Shop; L1, R1, L1, R2             ----      (L2,R3,)  

            String str = "2017-01-01; Coffee Shop; L2, L5, L5, R5, L2 ";
            
            Solution2 sol = new Solution2(str);
            sol.solve();
        }
    }
}
