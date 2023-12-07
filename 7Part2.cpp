#include <set>
#include <iostream>
#include <string>
#include <vector>
#include <map>
 
using namespace std;
 
#define input freopen("input.txt","r",stdin); 
#define rep(i,n)        for (int i=0;i<n;i++)

map<char,char> mp;
bool fiveOfAkind(string str) {
	set<char> st;
	rep(i,str.size()) st.insert(str[i]);
	return st.size()==1;
}
bool fourOfAKind(string str) {
	rep(i,str.size()-3) {
		if(str[i]==str[i+1]&&str[i]==str[i+2]&&str[i]==str[i+3]) return 1;
	}
	return 0;
}
bool fullHouse(string str) {
	if((str[0]==str[1]&&str[2]==str[3]&&str[4]==str[2])||(str[0]==str[1]&&str[2]==str[0]&&str[4]==str[3])) return 1;
	return 0;
	
}
bool threeOfAKind(string str) {
	rep(i,str.size()-2) {
		if(str[i]==str[i+1]&&str[i]==str[i+2]) return 1;
	}
	return 0;
}
bool twoPair(string str) {
	bool f=0;
	rep(i,str.size()-1) {
		if(str[i]==str[i+1]) {
			if(f==1) return 1;
			else f=1;
		}
	}
	return 0;
}
bool onePair(string str) {
	rep(i,str.size()-1) {
		if(str[i]==str[i+1]) return 1;
	}
	return 0;
}
int calculateType(string str) {
	sort(str.begin(),str.end());
	int countJ =0;
	rep(i,str.size()) {
		if(str[i]=='N') countJ++;
	}
	if(fiveOfAkind(str)) {return 1;}
	else if(fourOfAKind(str)) {
		if(countJ>0) return 1; 
		else return 2;
	} else if(fullHouse(str)) {
		if(countJ>0) return 1;
		return 3;
	} else if(threeOfAKind(str)) {
		if(countJ>0) return 2;
		return 4;
	} else if(twoPair(str)) {
		if(countJ==1) {
			return 3;
		} else if(countJ==2) {
			return 2;
		}
		return 5;
	} else if(onePair(str)) {
		if(countJ>0) {
			return 4;
		}
		return 6;
	} else {
		if(countJ>0) return 6;
		return 7;
	}
}
string transform(string str) {
	string str2="";
	rep(i,str.size()) {
		str2+=mp[str[i]];
	}
	return str2;
}

bool CustomComparator (pair< pair<int,string>, long long> a, pair< pair<int,string>, long long> b)
{
    if(a.first.first<b.first.first) return 1;
    else if(a.first.first>b.first.first) return 0;
    else return(a.first.second<b.first.second);
    return 0;
}
int main()
{
    input;
	int n,i,j,k,m,t,s=0;
	long long bid;
	vector< pair< pair <int,string>, long long > > vv;
	mp['A'] = 'A';
	mp['K'] = 'B';
	mp['Q'] = 'C';
	mp['J'] = 'N'; //mp['J'] = 'D' for part 1;
	mp['T'] = 'E';
	mp['9'] = 'F';
	mp['8'] = 'G';
	mp['7'] = 'H';
	mp['6'] = 'I';
	mp['5'] = 'J';
	mp['4'] = 'K';
	mp['3'] = 'L';
	mp['2'] = 'M';
	string str,str1,str2,color;
	long long result = 0,a=0,c,minRed,minBlue,minGreen;
	minRed=minGreen=minBlue=0;
	bool f=0;
	cin>>t;
	while(t--){
		cin>>str>>bid;
		str=transform(str);
		int rank = calculateType(str);
		vv.push_back(make_pair(make_pair(rank,str),bid));
	}
	sort(vv.begin(),vv.end(),CustomComparator);
	rep(i,vv.size()) a+=vv[i].second*(vv.size()-i);
	cout<<a<<endl;
	return (0);
}
