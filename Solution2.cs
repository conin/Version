using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Maps
{

    public enum Direction
    {
        East,
        West,
        North,
        South
    };

    class Solution2
    {
        public string[] mainString;
        public int Horizantal;
        public int Vertical;
        input[] values;
        
        public Solution2()
        {

        }

        public Solution2(String str)
        {
            mainString = str.Split(';');
            String[] str1 = mainString[mainString.Length - 1].Split(',');
            values = new input[str1.Length];
            int i = 0;

            foreach (String ch in str1)
            {
                char[] char1 = ch.ToCharArray();

                values[i] = new input();
                values[i].direction = char1[1];
                values[i].blocks = (int)char.GetNumericValue(char1[2]);

                i++;
            }

        }

        public String firstAxis(int x, int y)
        {
            String str = "";

            if (x<y)
            {
                str += " R" + x+ " L" + y;
            }
            else
            {
                str += " R" + y+ " R" + x;
            }

            return str;
        }

        public String secondAxis(int x, int y)
        {
            String str = "";

            x *= -1;

            if (y>x)
                str += " R" + x + " L" + y;
            else
                str += " R" + y + " L" + x;

            return str;
        }

        public String thirdAxis(int x, int y)
        {
            String str = "";

            x *= -1;
            y *= -1;

            if (x < y)
            {
                str += " L" + y + " R" + x;
            }
            else
            {
                str += " L" + y + " R" + x;
            }

            return str;
        }

        public String fourthAxis(int x, int y)
        {
            String str = "";

            y *= -1;

            if (x > y)
            {
                str += " L" + y + " R" + x;
            }
            else
            {
                str += " L" + x + " R" + y;
            }
            return str;
        }
        
        public void solve()
        {
            Direction towards = Direction.West;

            
            for (int i = 0; i < values.Length; i++)
            {
                int blocksValue = values[i].blocks;
                char direction = values[i].direction;

                if (direction == 'R')
                {
                    if (towards == Direction.East)
                    {
                        Vertical -= blocksValue;
                        towards = Direction.South;                    
                    }
                    else if (towards == Direction.West)
                    {
                        Vertical += blocksValue;
                        towards = Direction.North;
                    }
                    else if (towards == Direction.North)
                    {
                        Horizantal += blocksValue;
                        towards = Direction.East;
                    }
                    else if (towards == Direction.South)
                    {
                        Horizantal -= blocksValue;
                        towards = Direction.West;
                    }
                }
                else if (direction == 'L')
                {
                    if (towards == Direction.East)
                    {
                        Vertical += blocksValue;
                        towards = Direction.North;
                    }
                    else if (towards == Direction.West)
                    {
                        Vertical -= blocksValue;
                        towards = Direction.South;
                    }
                    else if (towards == Direction.North)
                    {
                        Horizantal -= blocksValue;
                        towards = Direction.West;
                    }
                    else if (towards == Direction.South)
                    {
                        Horizantal += blocksValue;
                        towards = Direction.East;
                    }
                }
            }

            towards = Direction.West;

            if (Horizantal >= 0 && Vertical >= 0)
                mainString[mainString.Length - 1] = firstAxis(Horizantal,Vertical);
            else if (Horizantal <= 0 && Vertical >= 0)
                mainString[mainString.Length - 1] = secondAxis(Horizantal, Vertical);
            else if (Horizantal <= 0 && Vertical <= 0)
                mainString[mainString.Length - 1] = thirdAxis(Horizantal, Vertical);
            else if (Horizantal >= 0 && Vertical <= 0)
                mainString[mainString.Length - 1] = fourthAxis(Horizantal, Vertical);

            String str="";

            for (int i = 0; i < mainString.Length-1; i++)
            {
               str += mainString[i] + ";";
            }

            str += mainString[mainString.Length-1];
            Console.WriteLine(str);
        }
    }
}
