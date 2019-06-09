#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set> 
#include <queue>
#include <algorithm>
#include <math.h>
#include <list>
#include <utility>
using namespace std;
const int maxn = 2010;
const int inf = 0x3ffffff;
int min(int a,int b){return a>b?b:a;}
int max(int a,int b){return a>b?a:b;}

struct dizi
{
    int nei;
    int wu;
    int life;
    double attack;
    int pos_x,pos_y;
    int moveDirX,moveDirY;
    char m_type;
    list<dizi*>(*m_wuLinShiJie)[12][12];
//    dizi(int x,int y,int n,int w,int l):pos_x(x),pos_y(y),nei(n),wu(w),life(l){}
    dizi():m_wuLinShiJie(NULL){}
//    dizi(){}
    virtual double cal_attack()=0;
    virtual void cal_step()=0;

    void move()
    {
        list<dizi*> &old=(*m_wuLinShiJie)[pos_x][pos_y];
        for(list<dizi*>::iterator it = old.begin() ; it!=old.end() ; ++it)
        {
            if(*it==this)
            {
                old.erase(it);
                break;
            }
        }
        cal_step();
        (*m_wuLinShiJie)[pos_x][pos_y].push_back(this);
    }
};

struct shaolin:public dizi
{
    shaolin()
    {
        moveDirX=1;
        moveDirY=0;
    }
    virtual double cal_attack()
    {
        attack=floor((0.5*nei+0.5*wu)*(life+10)/100);
        return attack;
    }
    virtual void cal_step()
    {
        if(moveDirX>0)
        {
            if(pos_x==11)
                moveDirX=-1;
            pos_x+=moveDirX;
        }
        else if(moveDirX<0)
        {
            if(pos_x==0)
                moveDirX=1;
            pos_x+=moveDirX;
        }
    }
};

struct wudan:public dizi
{
    wudan()
    {
        moveDirX=0;
        moveDirY=1;
    }
    virtual double cal_attack()
    {
        attack=floor((0.8*nei+0.2*wu)*(life+10)/100);
        return attack;
    }
    virtual void cal_step()
    {
        if(moveDirY>0)
        {
            if(pos_y==11)
            {
                moveDirY=-1;
            }
            pos_y+=moveDirY;
        }
        else
        {
            if(pos_y==0)
                moveDirY=1;
            pos_y+=moveDirY;
        }
    }
};

struct emei:public dizi
{
    emei()
    {
        moveDirX=1;
        moveDirY=1;
    }
    virtual double cal_attack()
    {
        attack=floor((0.2*nei+0.8*wu)*(life+10)/100);
        return attack;
    }
    virtual void cal_step()
    {
        if((pos_x==0&&pos_y==11)||(pos_x==11&&pos_y==0))
            return;
        if(moveDirX>0)
        {
            if(pos_x==11)
            {
                moveDirX=-1;
                moveDirY=-moveDirY;
            }
            else if(moveDirY>0&&pos_y==11)
            {
                moveDirX=-moveDirX;
                moveDirY=-moveDirY;
            }
            else if(moveDirY<0&&pos_y==0)
            {
                moveDirX=-moveDirX;
                moveDirY=-moveDirY;
            }
            pos_x+=moveDirX;
            pos_y+=moveDirY;
        }
        else
        {
            if(pos_x==0)
            {
                moveDirX=1;
                moveDirY=-moveDirY;
            }
            else if(moveDirY>0&&pos_y==11)
            {
                moveDirX=-moveDirX;
                moveDirY=-moveDirY;
            }
            else if(moveDirY<0&&pos_y==0)
            {
                moveDirX=-moveDirX;
                moveDirY=-moveDirY;
            }
            pos_x+=moveDirX;
            pos_y+=moveDirY;
        }
    }
};

void play_game(int step,const vector<shaolin>& Shao,const vector<wudan>& Wu,const vector<emei>& Em)
{
    int i;
    for( i = 0 ; i < step ; i++)
    {
        
    }
}

int main()
{
#ifdef _DEBUG
    freopen("in.txt","r",stdin);
#endif
    int t,step,nei,wu,life,x,y,i,j,a,b;
    string s;
    cin>>t;
    while(t--)
    {
        list<dizi*>wuLinShiJie[12][12];
        set<dizi*>diZiSet;
        cin>>step;
        while(cin>>s)
        {
            if(s[0]=='0')break;
            dizi *d = NULL;
            if(s[0]=='S')
            {
                d = new shaolin;
            //    Shao.push_back(A);
            }
            else if(s[0]=='W')
            {
                d = new wudan;
        //        Wu.push_back(A);
            }
            else if(s[0]=='E')
            {
                d = new emei;
            //    Em.push_back(A);
            }
            d->m_type=s[0];
            cin>>d->pos_x>>d->pos_y>>d->nei>>d->wu>>d->life;
            d->m_wuLinShiJie=&wuLinShiJie;
            --d->pos_x;
            --d->pos_y;
            wuLinShiJie[d->pos_x][d->pos_y].push_back(d);
            diZiSet.insert(d);
        }
    //    play_game(step,Shao,Wu,Em);
        for( j = 0 ; j < step ; ++j)
        {
            for( a = 0 ; a < 12 ; ++a)
            {
                for( b = 0 ; b < 12 ; ++b)
                {
                    list<dizi*> &l=wuLinShiJie[a][b];
                    if(l.size()!=2)
                        continue;
                    if(l.front()->m_type==l.back()->m_type)
                        continue;
                    int fg=(int)l.front()->cal_attack();
                    int bg=(int)l.back()->cal_attack();
                    l.front()->life-=bg;
                    l.back()->life-=fg;
                    if(l.front()->life<=0)
                    {
                        diZiSet.erase(l.front());
                        delete l.front();
                        l.pop_front();
                    }
                    if(l.back()->life<=0)
                    {
                        diZiSet.erase(l.back());
                        delete l.back();
                        l.pop_back();
                    }
                }
            }
            for(set<dizi*>::iterator it = diZiSet.begin() ; it!=diZiSet.end() ; ++it)
            {
                dizi *d=*it;
                d->move();
            }
        }
        int sc=0,wc=0,ec=0;
        int ss=0,ws=0,es=0;
        for(set<dizi*>::iterator it = diZiSet.begin() ; it!=diZiSet.end() ; ++it)
        {
            dizi *d =*it;
            if(d->m_type=='S')
            {
                ++sc;
                ss+=d->life;
            }
            else if(d->m_type=='W')
            {
                ++wc;
                ws+=d->life;
            }
            else if(d->m_type=='E')
            {
                ++ec;
                es+=d->life;
            }
            delete d;
        }
        cout<<sc<<" "<<ss<<endl;
        cout<<wc<<" "<<ws<<endl;
        cout<<ec<<" "<<es<<endl;
        cout<<"***"<<endl;
    }
    return 0;
}