/*
recursion, backtracking, divide and conquer
array reverse num by divide and conquer
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    vector<int> countSmaller(vector<int>& nums){
        vector<pair<int, int>> vec;
        vector<int> count;
        for (int i = 0; i < nums.size(); i++){
            vec.push_back(make_pair(nums[i],i));
            count.push_back(0);
        }
        merge_sort(vec, count);
        return count;
    }
private:
    void merge_sort_two_vec(vector<pair<int, int>> &sub_vec1,
                            vector<pair<int, int>> &sub_vec2,
                            vector<pair<int, int>> &vec,
                            vector<int> &count){
        int i = 0;
        int j = 0;
        while(i < sub_vec1.size() && j < sub_vec2.size()){
            if (sub_vec1[i].first <= sub_vec2[j].first){
                count[sub_vec1[i].second] += j;
                vec.push_back(sub_vec1[i]);
                i++;
            }
            else{
                vec.push_back(sub_vec2[j]);
                j++;
            }
        }
        for (; i < sub_vec1.size(); i++){
            count[sub_vec1[i].second] += j;
            vec.push_back(sub_vec1[i]);
        }
        for (; j < sub_vec2.size(); j++){
            vec.push_back(sub_vec2[j]);
        }

    }
    void merge_sort(vector<pair<int, int>> &vec,
                    vector<int> &count){
        if (vec.size() < 2) return;
        int mid = vec.size()/2;
        vector<pair<int, int>> sub_vec1;
        vector<pair<int, int>> sub_vec2;
        for (int i = 0; i < mid; i++){
            sub_vec1.push_back(vec[i]);
        }
        for (int i = mid; i < vec.size(); i++){
            sub_vec2.push_back(vec[i]);
        }
        merge_sort(sub_vec1, count);
        merge_sort(sub_vec2, count);
        vec.clear();
        merge_sort_two_vec(sub_vec1, sub_vec2, vec, count);
    }
};

int main(){
    int test[] = {5, -7, 9, 1, 3, 5, -2, 1};
    vector<int> nums;
    for (int i = 0; i < 8; i++){
        nums.push_back(test[i]);
    }
    Solution solve;
    vector<int> result = solve.countSmaller(nums);
    for (int i = 0; i < result.size(); i++){
        cout<<"["<<result[i]<<"]";
    }
    cout<<endl;
    return 0;
}
