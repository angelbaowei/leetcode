class Solution {
public:
    
    vector<int> getNext(char* ms){
        int l=strlen(ms);
        vector<int> next(l);
        if(l==1){
            next[0]=-1;
            return next;
        }
        next[0]=-1;
        next[1]=0;
        int pos=2;
        int cn=0;
        while(pos<next.size()){
            if(ms[pos-1]==ms[cn])
                next[pos++]=++cn;
            else if(cn>0)
                cn=next[cn];
            else
                next[pos++]=0;
        }
        return next;
    }
    char *strStr(char *haystack, char *needle) {
        int l1=strlen(haystack),l2=strlen(needle);
        if(l1<l2)
            return NULL;
        if(l1==0||l2==0)
            return haystack;
        int si=0,mi=0;
        vector<int> next=getNext(needle);
        while(si<l1&&mi<l2){
            if(haystack[si]==needle[mi]){
                si++;
                mi++;
            }else if(next[mi]==-1){
                si++;
                mi=0;
            }else{
                mi=next[mi];
            }
        }
        return mi==l2 ? &haystack[si-mi] : NULL;
        }
};