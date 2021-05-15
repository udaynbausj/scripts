#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct activity{
    int start , finish , index;
};

bool compare(activity a , activity b) {
    return a.finish < b.finish;
}

int main() {
    int test;
    cin>>test;
    while(test--) {
        int count = 1;
        int len;cin>>len;
        vector<activity>activity_vector(len);
        for (int i = 0 ; i < len ; i ++ ) {
            cin>>activity_vector[i].start;
            activity_vector[i].index = i+1;
        }
        for (int i = 0 ; i < len ; i ++ ) {
            cin>>activity_vector[i].finish;
        }
        sort(activity_vector.begin(),activity_vector.end(),compare);

        int finish_time = activity_vector[0].finish;
        cout<<activity_vector[0].index<<" ";
        for (int i = 1 ; i < len ; i ++ ) {
            if (activity_vector[i].start >= finish_time ) {
                count++;
                finish_time = activity_vector[i].finish;
                cout<<activity_vector[i].index<<" ";
            }
        }
//        cout<<count<<"\n";
    }
}