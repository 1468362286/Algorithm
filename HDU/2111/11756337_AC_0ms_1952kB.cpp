#include <iostream>
#include <algorithm>
using namespace std;
struct Note
{
    int pi;
    int mi;
}note[100];
bool compare(struct Note note1,struct Note note2)
{
    return note1.pi>note2.pi;//降序
}
int main()
{
    int i,v,n;
    while(cin>>v,v!=0)
    {
        cin>>n;
        for( i = 0 ; i < n ; i++)
        {
            cin>>note[i].pi>>note[i].mi;        
        }
        sort(note,note+i,compare);
        i = 0;
        int sum = 0;
        while(i<n)
        {
            if(v>=note[i].mi)
            {
                v-=note[i].mi;
                sum+=note[i].mi*note[i].pi;
            }
            else
            {
                sum+=note[i].pi*v;
                break;
            }
            i++;
        }
        cout<<sum<<endl;
    }

    return 0;
}