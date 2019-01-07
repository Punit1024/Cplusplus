#include <iostream>

using namespace std;

void showMap(bool map[10][10]){
    cout << endl;
    cout << endl;
    cout << "# # # # # # # # # # # #" << endl;
    for(int i = 0; i<10;i++){
        cout << "# ";
        for(int j = 0; j<10;j++){
                if(map[i][j])
                    cout << "  ";
                else
                    cout << "# ";
        }
        cout << "#"<< endl;
    }
    cout << "# # # # # # # # # # # #" <<endl;
    cout<<endl;
}


bool unvisitedNodesExists(bool unvisitedNodes[10][10]){
    for(int i = 0; i<10;i++)
    {
        for(int j = 0; j<10;j++)
        {
            if(unvisitedNodes[i][j])
            {
                return true;
            }
        }

    }
    return false;
}


int main()
{
    //creating a open map
    bool map[10][10] =
     {
        { 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 },
        { 0 , 0 , 0 , 0 , 0 , 1 , 0 , 0 , 0 , 0 },
        { 1 , 1 , 0 , 1 , 0 , 1 , 1 , 1 , 1 , 1 },
        { 1 , 0 , 0 , 1 , 0 , 0 , 0 , 0 , 0 , 1 },
        { 1 , 1 , 1 , 0 , 0 , 0 , 0 , 0 , 0 , 1 },
        { 1 , 1 , 0 , 0 , 1 , 1 , 1 , 1 , 1 , 1 },
        { 1 , 0 , 0 , 1 , 1 , 1 , 1 , 1 , 1 , 1 },
        { 1 , 0 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 },
        { 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 },
        { 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 }

    };

    /*{false};
    for(int i = 0; i<10;i++){
        for(int j = 0; j<10;j++){
            map[i][j]=true;
            cout << map[i][j];
        }
        cout << endl;
    }

    //building walls
    map[3][5] = 0;
    map[4][5] = 0;
    map[5][5] = 0;
    map[6][5] = 0;
    map[7][5] = 0;
    map[5][1] = 0;
    map[5][2] = 0;
    map[5][3] = 0;*/
    showMap(map);

    //Setting start and destination
    int startPoint[2] = {0,0};
    int endPoint[2] = {2,1};
    cout << "Start point - "<<startPoint[0]<< ", " << startPoint[1] << endl;
    cout << "End point - "<<endPoint[0]<< ", " << endPoint[1] << endl;

    //set Distance for all nodes to inf.
    int distanceFromStart[10][10];
    for(int i = 0; i<10;i++){
        for(int j = 0; j<10;j++){
            distanceFromStart[i][j] = 2560;

        }

    }

    bool unvisitedNodes[10][10];

    for(int i = 0; i<10;i++){
        for(int j = 0; j<10;j++){
            unvisitedNodes[i][j] = true;

        }
    }

    //remove wall nodes from unvisited nodes....
    for(int i = 0; i<10;i++){
        for(int j = 0; j<10;j++){
        if(map[i][j] == false){
            unvisitedNodes[i][j] = false;
        }
        }

    }


    distanceFromStart[startPoint[0]][startPoint[1]] = 0;
    while(unvisitedNodesExists( unvisitedNodes )){
            //find next node with min distance from start
            int min= 2560;
            int idxi = 11;
            int idxj = 11;

            for (int i=0; i<10; i++)
            {
                for (int j=0; j<10; j++)
                {
                    if(!unvisitedNodes[i][j])
                        continue;

                    if(distanceFromStart[i][j]<min)
                    {
                        min = distanceFromStart[i][j];
                        idxi = i;
                        idxj = j;
                    }

                }
            }
            if(idxi==11){
                    break;
            }
            //Now idxi,idxj is current node;
            int currentRow = idxi;
            int currentColoumn = idxj;


            //cycling through Adjacent nodes
            for (int i=0; i<3; i++)
            {
                for (int j=0; j<3; j++)
                {
                    if(i==1&&j==1)
                        continue;
                    int cellR = currentRow - 1 + i;
                    int cellC = currentColoumn -1 + j;
                    if(cellR<0||cellR>9||cellC<0||cellC>9)
                       continue;
                    if(!unvisitedNodes[cellR][cellC])
                        continue;
                    if(i==1||j==1){
                        if(distanceFromStart[cellR][cellC] > distanceFromStart[currentRow][currentColoumn] + 10)
                        {
                            distanceFromStart[cellR][cellC] = distanceFromStart[currentRow][currentColoumn] + 10;
                        }
                    }
                    else{
                        if(distanceFromStart[cellR][cellC] > distanceFromStart[currentRow][currentColoumn] + 14)
                        {
                            distanceFromStart[cellR][cellC] = distanceFromStart[currentRow][currentColoumn] + 14;
                        }

                    }






                }
            }

            unvisitedNodes[currentRow][currentColoumn] = false;



    }
    cout << endl;
    cout << "Distance Matrix" << endl;
    for(int i = 0; i<10;i++)
    {
        cout << "# ";
        for(int j = 0; j<10;j++)
        {
            cout << distanceFromStart[i][j]<< " ";
        }
        cout << "#"<< endl;
    }

    cout<<endl;

    if(distanceFromStart[endPoint[0]][endPoint[1]]==2560)
    {
        cout << "No solution Exists"<< endl;
    }
    else
    {   int currentRow = endPoint[0];
        int currentColoumn = endPoint[1];
        int solution[40] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
        for(int i = 0;i<40;i++){
            cout<<" " <<solution[i]<<"   ";
        }
        cout<<endl;
        int stepCounter = 0;
        solution[stepCounter++] =  currentRow *10 +  currentColoumn;
        while(currentRow != startPoint[0] || currentColoumn != startPoint[1])
        {
            int minR = 11;
            int minC = 11;
            int minimum = 1500;
            for (int i=0; i<3; i++)
            {
                for (int j=0; j<3; j++)
                {
                    if(i==1&&j==1)
                        continue;
                    int cellR = currentRow - 1 + i;
                    int cellC = currentColoumn -1 + j;
                    if(cellR<0||cellR>9||cellC<0||cellC>9)
                       continue;
                    if(minimum>distanceFromStart[cellR][cellC])
                    {
                        minimum = distanceFromStart[cellR][cellC];
                        minR = cellR;
                        minC = cellC;
                    }




                }
            }

            currentRow = minR;
            currentColoumn = minC;
            solution[stepCounter++] =  currentRow *10 +  currentColoumn;
        }

        bool drSol[10][10] = {false};
        for(int i = 0;i<40;i++){
            if(solution[i]!= 0)
            {
                drSol[solution[i]/10][solution[i]%10] = true;
                cout<<" " <<solution[i]<<"  ";
            }
        }

        showMap(drSol);

    }

    return 0;
}
