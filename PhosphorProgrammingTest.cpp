/////////////////////////////////////////////////////////////////////////////////////////
//																						
//	The following is the Phosphor Games programming test. You have 2 hours
//	to complete the test. You may use any resources you wish including a compiler or IDE.		
//	Please make sure that your solutions compile without errors in the compiler of		
//	your choice. We also suggest that you test all or your answers. You may include 
//	any additional headers you wish from the C++ standard library.							
//
//////////////////////////////////////////////////////////////////////////////////////////

#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include<algorithm>
#include<iterator>

// Additional includes here. You may only include headers from the standard library.



// DO NOT MODIFY THIS STRUCT
struct Vec3D
{
	float x,y,z;

	Vec3D operator-(const Vec3D& V)
	{
		Vec3D Result;
		Result.x = x - V.x;
		Result.y = y - V.y;
		Result.z = z - V.z;
		return Result;	
	}
};


//////////////////////////////////////////////////////////////////////////////////////////
//
// QUESTION 1: below is a function that (assuming a bullet impact) is intended to determine 
// if a character was shot from in front or behind. Write the contents of the function. 
// Do not change the function signature. Use comments to explain your reasoning.
//
//////////////////////////////////////////////////////////////////////////////////////////


bool WasShotFromBehind(const Vec3D& bulletVelocity, const Vec3D& CharacterFacing)
{
	//if dot product is < 0 then bullet impact is behind otherwise it is in Frontside
	return (bulletVelocity.x*CharacterFacing.x +
			bulletVelocity.y*CharacterFacing.y +
			bulletVelocity.z*CharacterFacing.z) < 0 ? true : false;
}



//////////////////////////////////////////////////////////////////////////////////////////
//
// QUESTION 2: Write a function that reverses only the portion of a linked list that comes after 
// the element "TestElement" in the list, starting with that element. For example, given the initial 
// list "A-B-C-D-E-F-G" and TestElement of "D", the resulting list would be "A-B-C-G-F-E-D". Your 
// function should be as robust as possible making no assumptions about the validity of the initial list. 
// Use comments to explain your reasoning. Your function should return the head of the resulting list.
// Do not change the ListNode class.
//
//////////////////////////////////////////////////////////////////////////////////////////

struct ListNode
{
	ListNode* Next;
};


void ReverseElement(ListNode * tmp) 
{
	ListNode * tmp1=tmp->Next;

	if (tmp1->Next != 0) 
	{
		ReverseElement(tmp1);
		//assign current node next to previous element
		tmp1->Next = tmp;
	}
	else 
	{
		//last element
		tmp1->Next = tmp;
	}
}

ListNode* ReverseAfterTestElement(ListNode* Head, const ListNode* TestElement)
{
	//If test element is found
	if (Head != 0)
	{
		//finding last node
		ListNode *lastnode = Head, *sentinalNode = 0;

		//if we need to reverse the whole list
		if (lastnode==TestElement) 
		{
			sentinalNode = lastnode;

			while (lastnode->Next != 0)
			{
				lastnode = lastnode->Next;
			}

			ReverseElement(sentinalNode);
			sentinalNode->Next = 0;
			Head = lastnode;
		}
		else
		{
			//if we need to reverse the sublist
			while (lastnode->Next != 0)
			{
				if (lastnode->Next == TestElement)
				{
					//sentinal node is used to point towards last node.
					sentinalNode = lastnode;
				}
				//from lastnode we can start reverse the list.
				lastnode = lastnode->Next;
			}
			if (sentinalNode->Next->Next != 0)
			{
				//function will reverse the list 
				ReverseElement(sentinalNode->Next);
				
				//sentinal node should point to last node and update last element in updated list to 0
				sentinalNode->Next->Next = 0; 
				sentinalNode->Next = lastnode;
			}
		}
	}
	return Head;
}



//////////////////////////////////////////////////////////////////////////////////////////
//
// QUESTION 3: The code below is required to find all the COMMON assets between two levels. 
// The passed in asset lists may contain duplicate values, but the result must contain NO 
// duplicates. You can assume two assets are equivalent if and only if they are located at 
// the same memory address. Implement the FindCommonAssets function as optimally as possible, 
// given levels with thousands of assets and (potentially) many duplicate entries. The result
// should contain a single unique reference to every asset that is contained in BOTH level lists.
//
// EXAMPLE
// Level1 = 3,4,1,2,3,5,6
// Level2 = 4,6,8,2,3,4,9
// Out = 2,3,4,6
//
// Do not change the FindCommonAssets function signature. Use comments to explain your reasoning.
//
//////////////////////////////////////////////////////////////////////////////////////////



class Asset
{
public:
	Asset(int val) 
		: i(val) 
	{
	
	}

	int i;
};

bool find(std::vector<Asset*> common, int x)
{
	if (common.size() == 0)
		return true;
	else
	{

		for (int j = 0; j < common.size(); j++)
		{
			Asset *obj = common[j];

			if (obj->i == x)
				return false ;
		}
	}
	return true;
}


bool binarySearch(std::vector<Asset*>& Level, int ele)
{
	int size = Level.size();
	int low = 0, high=size, mid=(low+high)/2;
	Asset *obj=0;

	while (low < high) 
	{
		mid = (low + high) / 2;
		obj = Level[mid];
		if (obj->i == ele) 
		{
			return true;
		}
		else if (obj->i < ele)
		{
			low = mid + 1;
		}
		else 
		{
			high = mid - 1;
		}
	}
	return false;
}

void FindCommonAssets(const std::vector<Asset*>& LevelOneAssets,const std::vector<Asset*>& LevelTwoAssets,std::vector<Asset*>& outUniqueCommonAssets)
{
	std::vector<Asset*> one = LevelOneAssets, two = LevelTwoAssets,common;

	if (LevelOneAssets == LevelTwoAssets)
	{
		//if both are same then try to return one of them
		outUniqueCommonAssets = LevelOneAssets;
	}
	else 
	{
		std::vector<Asset*>::iterator it;
		std::sort(one.begin(), one.end(), [](Asset *one, Asset *two) {return one->i < two->i; });
		std::sort(two.begin(), two.end(), [](Asset *one, Asset *two) {return one->i < two->i; });

		for (int i = 0; i < one.size(); i++) 
		{
			for (int j = 0; j < two.size(); j++)
			{
				Asset *obj = one[i];
				Asset *obj2 = two[j];

				if (obj->i == obj2->i )
				{
					//If repeated element already exists we have to discard it.
					//as elements are already sorted we can use Binary search...O(logn)
				   if(!binarySearch(outUniqueCommonAssets, obj->i))
					   outUniqueCommonAssets.push_back(obj);
					break;
				}
			}
		}
	}
}



//////////////////////////////////////////////////////////////////////////////////////////
//
// QUESTION 4 - A departing programmer has written the following function that you will be expected
// to maintain. The function's comment and signature are correct, but the implementation is not.
// Fix all the potential bugs and programming errors, and refactor any bad practices that you can 
// find in the function below. Use comments to explain your reasoning. Do not modify the Character class.
//
//////////////////////////////////////////////////////////////////////////////////////////

// DO NOT MODIFY THIS CLASS
class Character
{
public:
	Vec3D Location;
	float MoveSpeed;
};

// Finds the Character that could reach the player's current location soonest
Character* FindCharacterToFirstReachPlayer(std::vector<Character*>& CharacterList, Character* Player)
{
	// Find the closest character
	Character* Closest;
	float MinTime = 10000.0f;
	int size = CharacterList.size();
	
	///First player time calculation
	Character* C = CharacterList.at(0);
	Vec3D CToP = C->Location - Player->Location;

	float Distance = sqrt(CToP.x * CToP.x + CToP.y * CToP.y + CToP.z * CToP.z);
	MinTime = Distance / C->MoveSpeed;

	/*
	   Velocity = distance / time;

	   time = distance/ Velocity;

	   who will take minimum time to reach the destination he wons..! Hurray..!
	*/

	for (int i = 1; i < size; i++)
	{
		Character* C = CharacterList.at(i);
		Vec3D CToP = C->Location - Player->Location;

		float Distance = sqrt(CToP.x * CToP.x + CToP.y * CToP.y + CToP.z * CToP.z);
		 
		if ((Distance/C->MoveSpeed) < MinTime)
		{
			Closest = C;
		}
	}

	return Closest;
}


//////////////////////////////////////////////////////////////////////////////////////////
//
// You may implement test cases for the functions here if you like.
//
//////////////////////////////////////////////////////////////////////////////////////////

int main(int argc, char* argv[])
{
	/*ListNode *l0 = new ListNode();
	l0->data = 0;

	ListNode *l1 = new ListNode();
	l1->data = 1;

	ListNode *l2 = new ListNode();
	l2->data = 2;

	ListNode *l3 = new ListNode();
	l3->data = 3;

	ListNode *l4 = new ListNode();
	l4->data = 4;

	ListNode *head = l0;
	l0->Next = l1;
	l1->Next = l2;
	l2->Next = l3;
	l3->Next = l4;
	l4->Next = 0;

	std::cout << "\nBefore Reverse - \n";
	head->print(head);
	head=ReverseAfterTestElement(head, l2);

	std::cout << "\nAfter Reverse at - "<<l2->data<<std::endl;
	head->print(head);


	std::cout << "\n\nBefore Reverse - \n";
	head->print(head);
	head = ReverseAfterTestElement(head, l1);

	std::cout << "\nAfter Reverse at - " << l1->data << std::endl;
	head->print(head);

	std::cout << "\n\nBefore Reverse - \n";
	head->print(head);
	head = ReverseAfterTestElement(head, l0);

	std::cout << "\nAfter Reverse at - " << l0->data << std::endl;
	head->print(head);

	std::cout << "\n\nBefore Reverse - \n";
	head->print(head);
	head = ReverseAfterTestElement(head, l0);

	std::cout << "\nAfter Reverse at - " << l0->data << std::endl;
	head->print(head);

	std::cout << "\n\nBefore Reverse - \n";
	head->print(head);
	head = ReverseAfterTestElement(head, l2);

	std::cout << "\nAfter Reverse at - " << l2->data << std::endl;
	head->print(head);

	std::cout << "\n\nBefore Reverse - \n";
	head->print(head);
	head = ReverseAfterTestElement(head, l3);

	std::cout << "\nAfter Reverse at - " << l3->data << std::endl;
	head->print(head);
	return 0;*/

	// Level1 = 3,4,1,2,3,5,6
	// Level2 = 4,6,8,2,3,4,9
	// Out = 2,3,4,6
	std::vector<Asset*> vec,vec1,common;
	vec.push_back(new Asset(3));
	vec.push_back(new Asset(4));
	vec.push_back(new Asset(1));
	vec.push_back(new Asset(2));
	vec.push_back(new Asset(3));
	vec.push_back(new Asset(5));
	vec.push_back(new Asset(6));

	vec1.push_back(new Asset(4));
	vec1.push_back(new Asset(6));
	vec1.push_back(new Asset(8));
	vec1.push_back(new Asset(2));
	vec1.push_back(new Asset(3));
	vec1.push_back(new Asset(4));
	vec1.push_back(new Asset(9));
	FindCommonAssets(vec, vec1, common);
}