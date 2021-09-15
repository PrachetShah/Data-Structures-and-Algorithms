#include <iostream>
using namespace std;

void findNemo(string nemo[]){
  for(int i=0; i<2; i++){
    if(nemo[i]=="nemo"){
      cout<<"Found NEMO!";
    }
  }
}

int main() {
  string nemo[2] = {"Hello","nemo"};
  findNemo(nemo);
  return 0;
}
