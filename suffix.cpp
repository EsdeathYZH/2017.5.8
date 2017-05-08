int main()
{
	cout<<"Please input the value of n:";
	int suffix_length;
	cin>>suffix_length;
	ifstream dicfile("dictionary.txt");
	multimap<string,string>word_map;
	map<string,int>num_map;
	multimap<int,string>suffix_map;
	string word_buffer;
	while(getline(dicfile,word_buffer))
	{
		if(word_buffer.length()<suffix_length)
			continue;
		word_map.insert(make_pair<string,string>(word_buffer.substr(word_buffer.length()-suffix_length),word_buffer));
		num_map[word_buffer.substr(word_buffer.length()-suffix_length)]++;
	}
	for(map<string,int>::iterator iter=num_map.begin();iter!=num_map.end();iter++)
	{
		suffix_map.insert(make_pair<int,string>(iter->second,iter->first));
	}
	while(1)
	{
		cout<<"想要打印数目前十的后缀，请输入1，想要查询后缀，输入2，否则退出."<<endl;
		int switch_num;
		cin>>switch_num;
		if(switch_num==1)
		{
			multimap<int,string>::iterator index=suffix_map.end();
			index--;
			for(int i=0;i<10;i++,index--)
			{
				cout<<index->first<<" "<<index->second<<endl;
			}
		}
		else if(switch_num==2)
		{
			while(1)
			{
				cin.sync();
				cin.clear();
				cout<<"Please input the suffix you want to query:(""to quit)";
				string suffix;
				getline(cin,suffix);
				if(suffix.length()==0)
					break;
				if(suffix.length()!=suffix_length)
				{
					cout<<"Your suffix is invalid!"<<endl;
					continue;
				}
				multimap<string,string>::iterator suffix_iter=word_map.find(suffix);
				if(suffix_iter==word_map.end())
				{
					cout<<"Can't find this suffix!"<<endl;
					continue;
				}
				for(int i=0;i<word_map.count(suffix);i++,suffix_iter++)
				{
					cout<<suffix_iter->second<<endl;
				}
			}
		}
		else break;
	}
	cout<<"Quiting..."<<endl;
	system("pause");
	return 0;
}#include<iostream>
#include<stack>
#include<queue>
#include<string>
#include<fstream>
#include<set>
#include<map>
#include<list>
using namespace std;
