#include<iostream>

using namespace std;

int maximum_element(int a,int b,int c ){
    if(a>b){
        if(a>c) return a;
        else return c;
    }
    else{
        if(b>c) return b;
        else return c;
    }
}


int main()
{
    string s1 = "GGTCTGTTGCAAACAC";
    string s2 = "CAAAGTGCGCGTTAAT";
    
    int match_score = 5;
    int mismatch_score = -4;
    
    int l1 = s1.length();
    int l2 = s2.length();
    
    int alignment_matrix[l2+1][l1+1];
    
    //initialize
    for (int i = 0; i < l2+1; i++) {
                alignment_matrix[0][i] = 0;
        }
        
    for (int j = 0; j < l1+1; j++){
        alignment_matrix[j][0] = 0;
    }
    
    int max_score = 0;
    int max_i,max_j;
    
    for(int i=1;i<l2+1;i++){            //i = every row
        for(int j=1;j<l1+1;j++){
            // match
            if(s1[j-1] == s2[i-1]){
                alignment_matrix[i][j] = alignment_matrix[i-1][j-1] +match_score;
                
            }
            else{
                alignment_matrix[i][j] = maximum_element(alignment_matrix[i-1][j],alignment_matrix[i][j-1],alignment_matrix[i-1][j]-1)+mismatch_score;
            }
            
            if(alignment_matrix[i][j] > max_score){
                max_score = alignment_matrix[i][j];
                max_i = i;
                max_j = j;
            }
        }
        
    }
    
    int i = max_i;
    int j = max_j;
    
    while((i!=0 && j!=0)){
        if(s1[j-1] == s2[i-1]){
            cout << s1[j-1] << '\t' << s2[i-1] << endl;
            i -= 1;
            j -= 1;
        }
        
        else{
            if(alignment_matrix[i-1][j] > alignment_matrix[i][j-1] && alignment_matrix[i-1][j] > alignment_matrix[i-1][j-1]){
                cout << '_' << '\t' << s2[i-1] << endl;
                i--;
            }
        
            else if(alignment_matrix[i][j-1] > alignment_matrix[i-1][j] && alignment_matrix[i][j-1] > alignment_matrix[i-1][j-1]){
                cout << s1[j-1] << '\t' << '_' << endl;
                j--;
            }
            /*else if(alignment_matrix[i-1][j-1] > alignment_matrix[i-1][j] && alignment_matrix[i-1][j-1] > alignment_matrix[i][j-1])
                cout << s1[j] << '\t' << '_' << endl;*/
        }
    }
     cout << "Max i: " << max_i << endl << "Max j: " << max_j << endl;
    
    
    
     for (int i = 0; i < l2+1; i++) {
        for (int j = 0; j < l1+1; j++) {
            cout << alignment_matrix[i][j] << '\t';
        }
        cout << endl;
    }
}
