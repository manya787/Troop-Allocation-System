#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

int NO_PARENT = -1,p[9];
const char* region[9]= { "Kyiv", "Dnipro", "Sumy", "Lyman","Donbas", "Izyum", "Irpin", "Lviv","Odesa" };

void printPath(int currentVertex, vector<int> parents)
{

	if (currentVertex == NO_PARENT) {
		return;
	}
	printPath(parents[currentVertex], parents);
	cout << " -> "<<region[currentVertex] ;
}

void printSolution(int startVertex, vector<int> distances,vector<int> parents,int n)
{
	int nVertices = distances.size();

	cout << "\n" << region[startVertex] << " -> ";
	cout << region[n] << " \t\t\t ";
	cout << distances[n] << "\t\t\t";
	printPath(n, parents);
}

void dijkstra(vector<vector<int> > adjacencyMatrix,
			int startVertex)
{
	int nVertices = adjacencyMatrix[0].size();

	vector<int> shortestDistances(nVertices);

	vector<bool> added(nVertices);

	for (int vertexIndex = 0; vertexIndex < nVertices;
		vertexIndex++) {
		shortestDistances[vertexIndex] = INT_MAX;
		added[vertexIndex] = false;
	}

	shortestDistances[startVertex] = 0;

	vector<int> parents(nVertices);

	parents[startVertex] = NO_PARENT;

	for (int i = 1; i < nVertices; i++) {

		int nearestVertex = -1;
		int shortestDistance = INT_MAX;
		for (int vertexIndex = 0; vertexIndex < nVertices;
			vertexIndex++) {
			if (!added[vertexIndex]
				&& shortestDistances[vertexIndex]
					< shortestDistance) {
				nearestVertex = vertexIndex;
				shortestDistance
					= shortestDistances[vertexIndex];
			}
		}

		added[nearestVertex] = true;

		for (int vertexIndex = 0; vertexIndex < nVertices;
			vertexIndex++) {
			int edgeDistance
				= adjacencyMatrix[nearestVertex]
								[vertexIndex];

			if (edgeDistance > 0
				&& ((shortestDistance + edgeDistance)
					< shortestDistances[vertexIndex])) {
				parents[vertexIndex] = nearestVertex;
				shortestDistances[vertexIndex]
					= shortestDistance + edgeDistance;
			}
		}
	}
    int f=0;
    p[0]=0;
    for(int i=1;i<9;i++)
    {
        cout<<endl<<"Is "<<region[i]<<" in danger?"<<endl<<"Press 1 for yes and 0 for no.";
        cin>>p[i];
        if(p[i]!=0 && p[i]!=1)
        {
            cout<<"Wrong input"<<endl;
            return;
        }
    }
    cout << "Vertex\t\t\t\tTime (hrs.)\t\t\t    Path"<<endl;
    for(int i=1;i<9;i++)
    {
        if(p[i]==1)
        {
            f=1;
            printSolution(startVertex, shortestDistances, parents,i);
        }
    }
    if(f==0)
    cout<<endl << "None\t\t\t\tNone\t\t\tNone"<<endl<<endl<<"No area is in danger";
}

int max(int a, int b) { return (a > b) ? a : b; }

void printknapSack(int W, int wt[], int val[], int n)
{
    int i, w;
    int K[n + 1][W + 1];

    for (i = 0; i <= n; i++)
    {
        for (w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = max(val[i - 1] +
                    K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }

    int res = K[n][W];
     int x=0;
    w = W;
    for (i = n; i > 0 && res > 0; i--) {

        if (res == K[i - 1][w])
            continue;
        else {

            cout<<wt[i - 1] <<" soldiers to be deployed to "<<region[i-1]<<endl;
             x++;
            res = res - val[i - 1];
            w = w - wt[i - 1];
        }
    }
    if(x==0)
    {
       // system("color 04");
    cout<<"NO SOLDIERS TO BE DEPLOYED" <<endl;
    }

}


void intro()
{


//system("color 0b");

    string str = " ALGORITHM AND PROBLEM SOLVING LAB ";
    string str2 = " MINI PROJECT  ";

cout<< "\n\n\n\t\t\t\t\t--------------------------------------------" <<endl;
cout<< "\t\t\t\t\t\t";

    for (int i = 0; i<str.length(); i++)
    {
Sleep(50);
cout<< str[i];
    }

cout<< "\n\t\t\t\t\t\t  ";

    for (int i = 0; i< str2.length(); i++)
    {
Sleep(100);
cout<< str2[i];
    }
cout<< "\n\t\t\t\t\t--------------------------------------------" <<endl;

Sleep(1000);

    string top = "\n\n\t\t\t\t\t TROOP REINFORCEMENT ALLOCATION SYSTEM (UKRAINE EDITION)\n\n ";

    for (int i = 0; i<top.length(); i++)
    {
Sleep(100);
cout<< top[i];
    }

cout<< "\n\t-------------------------------\n"
<<endl;

    string crt = "\tCREATED & DEVELOPED BY : ";

    for (int i = 0; i<crt.length(); i++)
    {
Sleep(100);
cout<<crt[i];
    }
cout<< "\n\t------------------------- \n"
<<endl;
    string name_s = "\t1. VISHWAS KAUSHIK (9921103225)\n\t2. MANSI BAKSHI (9921103157)\n\t3. MANYA GARG (9921103162)\n\t4. SHUBH SHANKAR (9921103214)\n ";

    for (int i = 0; i<name_s.length(); i++)
    {
Sleep(100);
cout<<name_s[i];
    }
Sleep(1000);

    system("pause");
    system("cls");
}




int main()
{
    //intro();
    label:
     vector<vector<int> > adjacencyMatrix
		= { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
			{ 4, 0, 8, 0, 0, 0, 0, 11, 0 },
			{ 0, 8, 0, 7, 0, 4, 0, 0, 2 },
			{ 0, 0, 7, 0, 9, 14, 0, 0, 0 },
			{ 0, 0, 0, 9, 0, 10, 0, 0, 0 },
			{ 0, 0, 4, 0, 10, 0, 2, 0, 0 },
			{ 0, 0, 0, 14, 0, 2, 0, 1, 6 },
			{ 8, 11, 0, 0, 0, 0, 1, 0, 7 },
			{ 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
    int n;
    cout<<endl<<endl<<"WHICH COMMAND TO ENTER"<<endl;
    cout<<"ENTER 1 FOR ROUTE OF MEDICAL SUPPLIES"<<endl;
    cout<<"ENTER 2 FOR TROOP ALLOCATION"<<endl;
    cout<<"ENTER 3 TO KNOW ABOUT THE PROGRAM"<<endl;
    cout<<"ENTER 4 TO EXIT"<<endl;
    cin>>n;
    switch (n)
    {
        case 1:
        {
        system("cls");
        //system("color 02");


        dijkstra(adjacencyMatrix, 0);

        break;
        }
    case 2:
    {
       system("cls");
         //system("color 09");
         int f=0;
    int b[9];
    b[0]=0;
    for(int i=1;i<9;i++)
    {
        cout<<endl<<"Is "<<region[i]<<" in danger?"<<endl<<"Press 1 for yes and 0 for no.";
        cin>>b[i];
        if(b[i]!=0 && b[i]!=1)
        {
            cout<<"Wrong input"<<endl;
            goto label;
        }
    }
        cout<<endl<<endl<<"Number of soldiers in Reserves present at the Basecamp (Kyiv)"<<endl;
        int W;
        cin>>W;
        int s_our, s_opp,cas,amm,dist, wt[9],val[9];

        for (int i=1;i<9;i++)
        {
            if(b[i]==1)
        {
            cout<<endl<<endl<<"* Enter details for location "<<region[i]<<" *"<<endl<<endl;
            cout<<"Enter head count of soldiers that are fit to fight in your army : ";
            cin>>s_our;

            cout<<"Enter approximation of resistance faced in "<<region[i]<<" : ";
            cin>>s_opp;
            cout<<"Enter number of casualties : ";
            cin>>cas;
            cout<<"Enter ammount of ammunition left in quintals : ";
            cin>>amm;
            cout<<"Enter distance of "<<region[i]<<" from base camp in kms : ";
            cin>>dist;
             cout<<endl<<endl;
            wt[i]=(3*s_opp)-s_our;
            val[i]=(10000*s_our*amm)/(s_opp*cas*dist);
            if(wt[i]<0)
            {
                cout<<"0 soldiers to be deployed to "<<region[i]<<endl;
                val[i]=-1;
            }
            f=1;
        }

        else val[i]=-1;
        }
        if(f==1)
        {
            int a = sizeof(val) / sizeof(val[0]);
            printknapSack(W, wt, val, a);
        }
        else cout<<endl<<"NO AREA IS IN DANGER"<<endl<<endl;
        break;
    }
    case 3:
    {
        system("cls");
        system("color 03");
        cout<<"When a nation is engaged in a war, there are several fronts where the battles are being fought."<<endl<<" In such conditions, casualties and injuries are bound to happen."<<endl;
        cout<<"Shortage of resources at any front is possible."<<endl<<" In such a case, if an efficienttransportation system is not employed, there can be a huge setback.";
        cout<<" The project Troop Reinforcement Allocation System eases this task and helps the user find the best possible route for the same."<<endl;


        cout<<"The project aims to provide the war struck nations, an efficient way to allocate and distribute resources."<<endl;
        cout<<" The project is useful for the armed organizations to strategize their attacks and reinforce their defenses."<<endl;
        cout<<"It takes into account the current war situation between Ukraine and Russia and provides efficient solution from Ukraines perspective"<<endl;

        cout<<endl<<endl<<"THE 3:1 RULE"<<endl<<"This rule states that in order to win a battle for sure, the number of soldiers in our army, should be at least 3 times the soldiers in opposite army"<<endl;
        cout<<"We have used this concept to calculate the number of soldiers required at any front."<<endl;
        cout<<endl<<endl<<"THE WINNING CHANCES CALCULATION FORMULA."<<endl;
        cout<<"We took into account, various factors that can affect the winning chances of the troops at a certain front"<<endl;
        cout<<"Winning Chances is directly proportional to ammunition left (amm)"<<endl;
        cout<<"Winning Chances is directly proportional to soldiers in our army (s_our)"<<endl;
        cout<<"Winning Chances is inversly proportional to soldiers in opposite army (s_opp)"<<endl;
        cout<<"Winning Chances is inversly proportional to casualties that have occurred during the battle (cas)"<<endl;
        cout<<"Winning Chances is inversly proportional to distance between the basecamp and destination (dist)"<<endl<<endl;
        cout<<"All these factors contribute towards the formula for the calculation of winning chances at each battlefront"<<endl;
        cout<<endl<<"FORMULA :-"<<endl;
        cout<<"(100*s_our*amm)/(s_opp*cas*dist)";
        cout<<""<<endl;
        break;
    }
    case 4:
    {
        system("cls");
        system("color 06");
        cout<<"THANK YOU.";
        return 0;
    }
    default:
    {
        system("cls");
        system("color 0d");
        cout<<"Wrong Input";
    }
    }
    cout<<endl<<endl<<"DO YOU WISH TO CONTINUE?"<<endl<<"PRESS 1 FOR YES AND 0 FOR NO";
    cin>>n;
    if(n==1){
    system("cls");
    goto label;
    }
    else if(n==0)
    cout<<"THANK YOU.";
    else cout<<"Wrong Input";
    return 0;
}
