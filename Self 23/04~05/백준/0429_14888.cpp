/*
N개의 수로 이루어진 수열

수와 수 사이의 연산자를 넣어서 수식을 만듬 이때 주어진 수의 순서를 바꾸면 안됨
ex) 6개의 수는 덧셈,뺄셈,곱셈,나눗셈의 갯수를 주어지면 그걸로 갯수를 만들 수 있음

식의 계산은 우선순위를 무시하고 앞에서부터 진행 하고 음수를 양수로 나눌때는
양수로 바꾼뒤 몫은 취한 후 그 몫을 음수로 바꾼것과 같음

n개의 수와 n-1개의 연산자 

입력 -> n / 숫자 n개 연산자 +,-,*,/ 순서로 받게 됨
출력 -> 최댓값과 최솟값을 출력하면 됨
*/

#include <iostream>
#include <vector>

using namespace std;
int cal_arr[10];
int ans_min = 100000000;
int ans_max = -100000000;
void allocate_sign(int index,int *arr_sign,vector<int> v);


int main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    
    int n,tmp;
    vector<int> v;
    int arr_sign[4]; //+ - * / 순서대로 입력받음

    cin >> n;
    vector<int> calculate(n-1,0);

    for(int i = 0 ; i < n ; i++){
        cin>>tmp;
        v.push_back(tmp);
    }
    for(int i  = 0 ; i < 4;i++){
        cin>>arr_sign[i];
    }

    //부호의 갯수로 모든 조합을 진행하면 됨. -> 근데 여기서 부호를 한번 사용했다면 제외하는 방향으로?
    allocate_sign(0,arr_sign,v);
    
    cout<<ans_max<<"\n"<<ans_min<<"\n";

}


//전체를 백트래킹하면서 진행을한다. 끝에 도착하게 된다면 return을 진행
//그리고 연산을 진행한다. 
void allocate_sign(int index,int *arr_sign,vector<int> v){
    if(index == v.size() - 1)
        return;
    for(int i= 0;i < 4;i++){
        if(arr_sign[i] != 0){
            cal_arr[index] = i;
            arr_sign[i] -= 1;
            allocate_sign(index + 1,arr_sign,v);
            arr_sign[i] += 1;
        }
    }

    if(index == v.size() - 2){
        int result = v[0];
        for(int i = 0; i < v.size() - 1; i++){
            if(cal_arr[i] == 0){
                result += v[i+1];
            }else if(cal_arr[i] == 1){
                result -= v[i+ 1];
            }else if(cal_arr[i] == 2){
                result *= v[i + 1];
            }else{
                result /= v[i + 1];
            }
        }
        if(ans_min > result){
            ans_min = result;
        }
        if(ans_max < result){
            ans_max = result;
        }
        return;
    }


}

