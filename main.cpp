#include <bits/stdc++.h>

using namespace std;

class node {
public:
    string name ;
    char genders ;
    bool decision ;
    node *next ;
};
class staack {
    node *top ;
public :
    staack (){
        top = NULL ;
    }
    bool isempty (){
        if (top == NULL )
            return true ;
        else
            return false ;
    }
    void puch (char n , bool m , string s ){
        node *new_node = new node () ;
        new_node -> genders = n ;
        new_node -> decision = m ;
        new_node -> name = s ;
        if ( isempty() ){
            top = new_node ;
            new_node -> next = NULL ;
        }
        else {
            new_node -> next = top ;
            top = new_node ;
        }
    }
    void display ( bool a ){
        node *temp = top ;
        while ( temp != NULL ) {
            if (temp->decision == a)
                cout << temp -> name << endl ;
            temp = temp -> next ;
        }
    }
    int counter (char d ){
        node *temp = top ;
        int c = 0 ;
        while ( temp != NULL ){
            if ( temp -> genders == d )
                c ++ ;
            temp = temp -> next ;
        }
        return c ;
    }
};

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    staack g ;
    string e ;
    char s ;
    bool l ;
    string nnn ;
    int n ;
    cout << "please enter number of people : " ;
    cin >> n ;
    for (int i = 0 ; i < n ; i++ ){
        cout << "Enter your name , your gender and your decision : " << endl;
        cin >> e >> s >> nnn ;
        if ( (nnn == "yes") || (nnn == "Yes") ){
            g.puch(s , true , e) ;
        }
        else if ( (nnn == "No") || (nnn == "no") ){
           g.puch ( s , false , e) ;
        }
    }
    cout << "People who agreed " << endl ;
    g.display(true) ;
    cout << "People who disagreed " << endl ;
    g.display(false) ;
    cout << "The number of males" << endl <<g.counter('M')<< endl ;
    cout << "The number of females" << endl << g.counter('F') << endl ;

    return 0 ;
}
