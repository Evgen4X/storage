#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);

    int w, h;
    cin>>w>>h;
    if(h > w){
        int temp = w;
        w = h;
        h = temp;
    }

    int n;
    cin>>n;

    vector<int> types(n);
    for(int i = 0; i < n; ++i){
        int t;
        cin>>t;
        if(t <= w){
            types.push_back(t);
        }
    }

    bool is_possible = true;
    int answer = 0;
    int done = 0;

    for(int i = n - 1; i > -1; --i){
        int type = types[i];
        int times = w / type;
        if(h % type == 0){
            answer += times * (h / type);
            done += type * times;
        } else {
            int needed = h % type;
            int sol = 1;
            bool possible = true;
            for(int j = i - 1; j > -1; --j){
                if(needed % types[j] == 0){
                    sol = types[j];
                    break;
                } else if(j == 0){
                    possible = false;
                    break;
                }
            }
            if(possible){
                if(type % sol == 0){
                    answer += times * type + (type % sol) * sol;
                    
                    done += type * times;
                } else {
                    is_possible = false;
                    break;
                }
            }
        }
    }

    cout<<(is_possible ? answer : -1)<<endl;    

    return 0;
}
