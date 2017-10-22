#include <assert.h>
#include <map>
#include <limits>
#include<iostream>

template<class K, class V>
class interval_map 
{
	friend void IntervalMapTest();

private:
    std::map<K,V> m_map;
	
public:
	interval_map( V const& val) 
	{
        m_map.insert(m_map.begin(),std::make_pair(std::numeric_limits<K>::lowest(),val));
	}

	void assign(K const& keyBegin, K const& keyEnd, V const& val)
	{
		// INSERT YOUR SOLUTION HERE
		int size = (int)(keyEnd - keyBegin);//It defines (key,val)pairs have to be inserted/updated
		if (size <= 0)
		{
			//do nothing
		}
		else
		{
			typename std::map<K, V>::iterator it = m_map.begin();//iterator to parse map
			bool found = false;    //if value is found then set this to true

			while (it != m_map.end())
			{
				if (it->second == val)
				{
					//remove this and insert from beginning.
					//We cannot override key values(const)
					m_map.erase(it);
					found = true;
					break;
				}
				it++;
			}

			if (found)
			{
				K key = keyBegin; //start key value since we can't update const variable

				while (size > 0)
				{
					//insert new (key,value) pair 
					m_map[key] = val;
					key++;
					size--;
				}
			}
		}


	}
	

    V const& operator[]( K const& key ) const 
	{
        return ( --m_map.upper_bound(key) )->second;
    }
};

void IntervalMapTest()
{
}


int main()
{
	IntervalMapTest();

	interval_map<float, double> m_interval(5.3242);
	m_interval.assign(95.0f, 195.0f, 5.3242);
}