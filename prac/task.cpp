#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

struct Item{
    int start;
    int end;
    int profit;
};

bool compare(Item a, Item b)
{
    return a.start>b.start;
}


int tasks(vector <int> start,vector <int> end,vector <int> profit)
{
    int n =profit.size();
    vector <Item> items(n);

    for (int i = 0; i < n; ++i) {
        items[i] = {start[i], end[i], profit[i]};
    }
    sort(items.begin(), items.end(), compare);

    Item cur = items[0];




    return 0;


}

int main(){
    vector <int> start = {1,2,3,3};
    vector <int> end = {3,4,5,6};
    vector <int> profit = {50,10,40,70};

    tasks(start,end,profit);
    return 0;
}
