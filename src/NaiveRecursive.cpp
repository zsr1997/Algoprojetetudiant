#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

//const int S = 5;  //introduce the size of the square matrix









int find_nth(int item, vector<int> l, int n){
  //function to find the nth occurrence of <item> in array <l>
  int list_size = l.size();
  //list_size = sizeof(l);

  int k = 0;
  int i = 0;
  while(k!= n)
  {

    if (item == l[i])
    {k++;}

    i++;
    if(i> list_size){return -1;}

  }
  return i-1;

}


bool inlist(int item, vector<int> l){
  // function to check if item is in l
  int S = l.size();
  int k = 0;

  for(int i = 0; i<S;i++){
    if(item ==l[i])
      k++;
  }
  if(k==0){return false;}
  else{return true;}
}


void sum_lines(vector<int> &sums, vector<vector<int> > a_T){
  int  S = sums.size();
  for(int i=0;i<S;i++){
    //cout<<endl;
    for(int j = 0; j<S; j++){
      sums[i] = sums[i]+a_T[i][j];
    }
  }

}




void get_indexes(vector<int> sums, vector<int> sorted_sums, vector<int> &indexes){
  //function to return the indexes of the lines in their initial matrix
  // by the
  int S = indexes.size();
  int item, k,idx;
  //int count_0 = 0;
  for(int i = 0; i<S; i++){
    item = sorted_sums[i];

    k = 0;
    idx = -1;


    while(inlist(idx, indexes)){
      k++;
      idx = find_nth(item, sums, k);


      //if(idx==0 && count_0 == 0){count_0++;
      //break;}



    }

    indexes[i] = idx;


  }

}

void order_matrix_by_line_sum(vector< vector< int> > a_T, vector< vector< int> > &ordered, vector<int> indexes){
  int S = indexes.size();
  for(int i = 0;i<S;i++){
    int idx = indexes[i];
    for(int j = 0;j<S;j++){
      ordered[i][j] = a_T[idx][j];
    }
  }

}









int max_score(vector<vector<int> > M , vector<vector<int> > ordered, vector< vector<int> > &pairs, vector<int> chosen_students, int stud_count, vector<int> indexes){


  if (M.size() == 2)
  {
    int S = ordered.size();
    //cout.flush();

    //cout<<"in2";

    int proj1 = S-2;
    int proj2 = S-1;
    int stud1 =-1;
    int stud2 =-1;
    vector<int> search_list_1(S,0);
    vector<int> search_list_2(S,0);
    //populating the first search list
    for(int i = 0; i<S;i++){
      search_list_1[i] = ordered[proj1][i];
    }


    //populating the second search list
    for(int i = 0; i<S; i++){
      search_list_2[i] = ordered[proj2][i];

    }




    if(M[0][0]+M[1][1]>=M[0][1]+M[1][0])
    {


      int k1=2;
      stud1 = find_nth(M[0][0], search_list_1,1);






      if(inlist(stud1, chosen_students)==false){
        chosen_students[stud_count] = stud1;
        stud_count++;
      }
      else{
        while(inlist(stud1, chosen_students) == true){
          //cout<<endl<<"in while";
          stud1 = find_nth(M[0][0], search_list_1, k1);
          //cout<<"stud1 = "<<stud1;
          k1++;
        }
        chosen_students[stud_count] = stud1;
        stud_count++;

      }




      for(int i = 0; i<S; i++){
        if(inlist(i,chosen_students) == false){
          stud2 = i;
        }
      }



    }
    else{
      // cout<<endl<<"2nd option";


      int k1=2;
      stud1 = find_nth(M[1][0], search_list_1,1);

      //cout<<endl<<"inlistcheck"<<inlist(stud1, chosen_students);
      if(inlist(stud1, chosen_students)==false){
        chosen_students[stud_count] = stud1;
        stud_count++;
      }
      else{
        while(inlist(stud1, chosen_students)){
          //cout<<endl<<"inwhile";
          stud1 = find_nth(M[0][1], search_list_1, k1);
          k1++;
        }
        chosen_students[stud_count] = stud1;
        stud_count++;

      }



      for(int i = 0; i<S; i++){
        if(inlist(i,chosen_students) == false){
          stud2 = i;
        }
      }

    }


    pairs[proj1][0] = stud1;
    pairs[proj1][1] = indexes[proj1];
    pairs[proj2][0] = stud2;
    pairs[proj2][1] = indexes[proj2];

    return max(M[0][0] + M[1][1], M[0][1] + M[1][0] );}

  else
  {

    int S = ordered.size();
    int Size = M.size();
    int m = -1;
    int idx = -1;
    //find max of M[0]
    for (int i = 0; i< Size; i++){
      if(M[0][i]>m){
        m = M[0][i];
        idx = i;
      }}
    int proj = S - Size;
    vector<int> search_list(S,-1);

    for(int i = 0; i<S;i++){
      search_list[i] = ordered[proj][i];
    }

    int k = 2;
    int stud = -1;
    stud = find_nth(m,search_list, 1);




    //cout<<endl<<Size<<endl;


    if(inlist(stud, chosen_students)==false){


      chosen_students[stud_count] = stud;

      stud_count++;

    }
    else{

      while(inlist(stud, chosen_students)){

        stud = find_nth(m, search_list, k);
        k++;
      }
      chosen_students[stud_count] = stud;
      stud_count++;

    }




    pairs[proj][0] = stud;

    pairs[proj][1] = indexes[proj];


    //defining the new matrix

    int foo = 0;




    int new_size = Size-1;



    vector<vector<int> > new_mat( new_size , vector<int> (new_size, 0));


    //std::cout.flush();

    for(int i = 0; i< Size -1 ; i++){

      foo = 0;
      for(int j = 0; j< Size ; j++){
        if(j==idx){continue;}

        new_mat[i][foo] = M[i+1][j];
        foo++;
      }
    }





    return m+max_score(new_mat, ordered, pairs,chosen_students, stud_count, indexes);


  }


}



int main()
{

  const clock_t begin_time = clock();


  //5
  int S = 5;

  //int a[S][S]= {,2,3,5,1,4,5,4,1,3,2};

  vector<vector< int> > a(S,vector<int>(S,0));
  a[0][0]=1;
  a[0][1]=2;
  a[0][2]=3;
  a[0][3]=4;
  a[0][4]=5;
  a[1][0]=3;
  a[1][1]=4;
  a[1][2]=1;
  a[1][3]=2;
  a[1][4]=5;
  a[2][0]=4;
  a[2][1]=2;
  a[2][2]=5;
  a[2][3]=1;
  a[2][4]=3;
  a[3][0]=2;
  a[3][1]=3;
  a[3][2]=5;
  a[3][3]=1;
  a[3][4]=4;
  a[4][0]=5;
  a[4][1]=4;
  a[4][2]=1;
  a[4][3]=3;
  a[4][4]=2;
  //get the transpose
  vector<vector< int> > a_T(S , vector<int> (S, 0));


  for(int i=0;i<S;i++){

    for(int j = 0; j<S; j++){
      a_T[i][j] = a[j][i];
    }
  }

  vector<vector< int> > ordered(S , vector<int> (S, 0));


  vector<int> sums(S,0);




  sum_lines(sums, a_T);



  vector<int> indexes(S,-1);

  for(int i = 0; i<S; i++){
    indexes[i] = -1;
  }



  vector<int> sorted_sums(S,0);
  for(int i = 0;i<S;i++){
    sorted_sums[i] = sums[i];
  }

  //bubbleSort(sorted_sums, S);
  sort(sorted_sums.begin(), sorted_sums.end());

  //printArray(sorted_sums);

  get_indexes(sums,sorted_sums, indexes);

  //printArray(indexes);


  order_matrix_by_line_sum(a_T,ordered, indexes);



  vector<vector<int> > ordered_copy(S , vector<int> (S, 0));

  order_matrix_by_line_sum(a_T,ordered_copy, indexes);

  vector<vector<int> > pairs(S, vector<int>(2,0));

  vector<int> chosen_students(S,-1);


  int m;


  vector<vector<int> > M(S , vector<int> (S, 0));

  for(int i = 0;i<S;i++){
    for(int j = 0;j<S;j++){
      M[i][j]= ordered[i][j];
    }
  }



  m = max_score(M,ordered_copy, pairs, chosen_students, 0, indexes);


  /*
   cout<<"The final score is = "<<m<<endl;
   cout<<"The pairs are:"<<endl;

   for(int i= 0; i<S; i++){
   cout<<endl;
   for(int j = 0; j<2; j++)
   cout<<pairs[i][j]<<" ";
   }



   cout<<endl;





   std::cout <<endl<< "Time:"<< float( clock () - begin_time )/CLOCKS_PER_SEC;*/


  //cout<<endl<<"pairs"<<pairs[0][0]<<" "<<pairs[0][1];



  return 0;



}
