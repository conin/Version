//#include<map>
//#include<assert.h>
//#include<iostream>
//
//template<class K, class V>
//class interval_map
//{
//private:
//	std::map<K, V> m_map;
//
//public:
//	interval_map()
//	{
//		m_map.insert(0,'A');
//	}
//
//
//	interval_map(V const& val)
//	{
//		m_map.insert(m_map.begin(), std::make_pair(std::numeric_limits<K>::lowest(), val));
//	}
//
//	void assign(K const& keyBegin, K const& keyEnd, V const& val)
//	{
//		// INSERT YOUR SOLUTION HERE
//	}
//
//	V const& operator[](K const& key) const
//	{
//		return (--m_map.upper_bound(key))->second;
//	}
//};
//
//int main()
//{
//	std::pair<std::map<int, char>::iterator, bool> res;
//	std::map<int, char> obj,obj2;
//	
//	std::cout << "\n Initialzing <key,value> pair elements into map..!";
//	res=obj.insert(std::pair<int, char>(0, 'A'));
//	assert(res.second==true);
//
//	//obj.insert(std::pair<int, char>(3, 'B'));
//	//assert(res.second == true);
//
//	//obj.insert(std::pair<int, char>(6, 'C'));
//	//assert(res.second == true);
//
//	//obj.insert(std::pair<int, char>(10, 'D'));
//	//assert(res.second == true);
//	
//	std::cout << "Inserting all elements into Second map obj2..";
//	
//	std::map<int, char>::iterator it = obj.begin(),it2;
//	it2 = it;
//	int size = obj.size()-1, key = 0, key2 = 0;
//	char val;
//
//	while(it != obj.end() && size)
//	{
//		key = it->first, key2 = 0;
//		val = it->second;
//		
//		it2++;
//		key2 = it2->first-key;
//
//		for(int i=0;i<key2;i++)
//		{
//			obj2.insert(std::pair<int, char>(key,val));
//			key++;
//		}
//
//		it++;
//		size--;
//	}
//
//	obj2.insert(std::pair<int, char>(it->first, it->second));
//}