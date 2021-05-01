//   回溯算法就是暴力的遍历算法，需要将节点抽象成
//   路径和选择列表的方式，进行深度遍历(DFS)
//   其基本框架就是：
//       TraceBadk(路径， 选择列表){
//            if 满足结束条件：
//                  result.add(路径)
//                       
//            for 选择 in 选择列表：
//                做选择前判断合不合法
//                做选择
//                TraceBadk(路径， 选择列表)
//                撤销选择
//       }

#include<string>
#include<vector>
#include<iostream>

std::vector<std::vector<std::string> > res;


bool isvalid(std::vector<std::string>& track, int row, int col){
        int n = track.size();
    // 检查列是否有皇后互相冲突
    for (int i = 0; i < n; i++) {
        if (track[i][col] == 'Q')
            return false;
    }
    // 检查右上方是否有皇后互相冲突
    for (int i = row - 1, j = col + 1; 
            i >= 0 && j < n; i--, j++) {
        if (track[i][j] == 'Q')
            return false;
    }
    // 检查左上方是否有皇后互相冲突
    for (int i = row - 1, j = col - 1;
            i >= 0 && j >= 0; i--, j--) {
        if (track[i][j] == 'Q')
            return false;
    }
    return true;
}
void TraceBack(std::vector<std::string> track, int row)
{
    if (track.size() == row){       //满足结束条件
        res.push_back(track);
        return;
    }
    int n = track.size();
    for(int col=0; col<n; col++){
        if (!isvalid(track, row, col)){
            continue;
        } 
        track[row][col] = 'Q';
        TraceBack(track, row+1);
        track[row][col] = '.';
    }
    return;
}
 


int main(void)
{
    int N;
    std::cin>>N;
    std::vector<std::string> track(N, std::string(N,'.'));


    TraceBack(track, 0);

    std::cout<<"N*N has "<< res.size()<<" choice"<<std::endl;
    for(int i=0;i<res.size();i++){
        for (int j=0;j<res[i].size();j++){
            std::cout<<res[i][j]<<std::endl;
        }
        std::cout<<"================="<<std::endl;
    }
    return 0;
}