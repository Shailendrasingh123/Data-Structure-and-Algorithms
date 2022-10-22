#include <iostream>
#include <vector>
using namespace std;

class priority_queue{
    vector<int> pq;
    public:
    priority_queue(){

    }
    bool isempty(){
        if(pq.size()==0)return true;
        else return false;
    }
    int getsize(){
        return pq.size();
    }
    int get_min(){
        if(isempty())return 0;
        else return pq[0];
    }

    void insert(int data){
        pq.push_back(data);
        int index=getsize()-1;
        while(index>0){
            int par_ind=(index-1)/2;
            if(pq[par_ind]<=pq[index])break;
            else swap(pq[par_ind],pq[index]);
            index=par_ind;
        }
    }

    void delete_min(){
        if(isempty())return 0;
        swap(pq[0],pq[getsize()-1]);
        pq.pop_back();
        int index=0;
        while(((2*index)+1)<getsize()){
            if(((2*index)+2)>=getsize()){
                if(pq[(2*index)+1]<pq[index])swap(pq[index],pq[2*index+1]);
                break;
            }
            if(pq[(2*index)+1]>pq[index] && pq[(2*index)+2]>pq[index]) break;
            else{
                int small_child=pq[(2*index)+1]<pq[(2*index)+2]?(2*index)+1:(2*index)+2;
                swap(pq[index],pq[small_child]);
            }
            index=pq[(2*index)+1]<pq[(2*index)+2]?(2*index)+1:(2*index)+2;
            
        }
    }

    
};

int main()
{
    priority_queue pqueue;
    pqueue.insert(6);
    pqueue.insert(4);
    pqueue.insert(1);
    pqueue.insert(7);
    pqueue.insert(2);
    pqueue.insert(12);
    cout<<"mini of pq: "<<pqueue.get_min()<<endl;
    pqueue.delete_min();
    cout<<"mini of pq: "<<pqueue.get_min()<<endl;
    cout<<"size of pq: "<<pqueue.getsize()<<endl;
    
    return 0;
}
