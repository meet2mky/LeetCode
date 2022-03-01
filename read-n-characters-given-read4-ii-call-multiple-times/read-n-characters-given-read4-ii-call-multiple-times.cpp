/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

class Solution {
  char tf[5];
  int ex = 0, len = 0;
public:
    int read(char *buf, int n) {
      int i = 0;
      while(i < n){
        if(ex == 0){
          ex = read4(tf);
          len = 0;
        }
        if(ex == 0)break;
        while(i < n && len < ex){
          buf[i++] = tf[len++];
        }
        if(len == ex){
          ex = 0;
          len = 0;
        }
      }
      return i;
    }
};