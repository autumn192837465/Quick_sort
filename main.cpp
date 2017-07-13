#include <iostream>
#include <fstream>
#include <vector>
#include <time.h>
#include <stdlib.h>
#include <iomanip>
#include <cstdlib>
using namespace std;

vector<int> v;
vector<int> v_s;

void heapify(int n){
    int l=n*2+1;
    int r=n*2+2;
    int lar;
    if(l<=v.size()-1 && v[l]>v[n])
        lar=l;
    else
        lar=n;

    if(r<=v.size()-1 && v[r]>v[lar])
        lar=r;
    if(n!=lar){
        swap(v[n],v[lar]);
        heapify(lar);
    }
}
void build_heap(){

    for(int i=v.size()/2-1;i>=0;i--){
        heapify(i);
    }
}


void draw_tree(){
    int i=0,j=2;
    for(;i<v.size();i++){
        cout<<setw(5)<<left<<v[i]<<" ";
        if(i==j-2){
            cout<<endl;
            j*=2;
        }
    }
}
void sort_start(){
    while(v.size()!=0){
        v_s.push_back(*v.begin());
        v.erase(v.begin());
        build_heap();
    }

}
int main()
{
    ifstream fin("input.txt");
    int temp;

    while(fin>>temp){
        v.push_back(temp);
    }
    for(vector<int>::iterator it=v.begin();it!=v.end();it++)
        cout<<*it<<" ";
    //draw_tree();
    cout<<endl;
    build_heap();

    sort_start();

    cout<<endl;
    //draw_tree();

    for(vector<int>::iterator it=v_s.begin();it!=v_s.end();it++)
        cout<<*it<<" ";

    return 0;
}
