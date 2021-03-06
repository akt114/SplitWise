#include<bits/stdc++.h>
#define ll       long long int
#define ld      long double
#define pll 	pair<ll,ll>
#define vll 	vector<ll>
#define pb      push_back
#define fastIO 	ios_base::sync_with_stdio(0);\
               	cin.tie(NULL);\
               	cout.tie(NULL)
using namespace std;
 
void solve()
{

int no_of_trancsations,friends,count_of_transactions=0,amount;
string x,y;

// hashmap to store net amount against each person after completing all transcations
unordered_map<string,int> net;

// enter the number of transactions
// enter the number of friends
cin>>no_of_trancsations>>friends;

while(no_of_trancsations--)
{
	cin>>x>>y>>amount;
	// if person x is participating in a transation for the first time
	if(net.find(x)==net.end())
		net[x]=0;
	// if person y is participating in a transation for the first time
	if(net.find(y)==net.end())
		net[y]=0;
	//decrement amount from person x and increament in person  y. 
	net[x]-=amount;
	net[y]+=amount;
}

// multiset to store people whose net balance is non-zero.
multiset<pair<int,string>> m;
for(auto p:net)
{
	if(p.second!=0)
		m.insert({p.second,p.first});
}

while(!m.empty())
{
	auto l=m.begin();
	auto r=prev(m.end());

	int debit=l->first;
	string debit_person=l->second;
	int credit=r->first;
	string credit_person=r->second;

	// amoount which needs to be transferred
	int settled_amount=min(-debit,credit);
	debit+=settled_amount;
	credit-=settled_amount;

	count_of_transactions++;
	cout<<debit_person<<" pays "<<settled_amount<<" to "<<credit_person<<"\n";

	// remove the current state of amount
	m.erase(l);
	m.erase(r);

	// insert agin in multiset if there if pending amount.
	if(debit!=0)
		m.insert({debit,debit_person});
	if(credit!=0)
		m.insert({credit,credit_person});
}

cout<<"Reduced Number of transactions performed is "<<count_of_transactions<<"\n";


}

 
		

int main(){
	fastIO;
 
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	// freopen("output.txt", "w", stdout);
	#endif

		solve();

	// #ifndef ONLINE_JUDGE
	// // cout<<endl<<"Time Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec"<<endl;
	// #endif
 
	return 0;
}