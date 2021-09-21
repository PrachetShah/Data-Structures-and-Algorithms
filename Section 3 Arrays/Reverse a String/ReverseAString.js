//Function to reverse a string

function reverse(str){
  if(!str || typeof str != 'string' || str.length < 2 ) return str;

  let name = str.split('');
  let rev = [];
  for(let i=name.length-1; i>=0; i--){
    rev.push(name[i]);
  }
  return rev.join('');
}

str = 'My name is Prachet';
reverse(str);

/* 
Other Methods:
function reverse2(str){
  //check for valid input in both
  return str.split('').reverse().join('');
}
const reverse3 = str => [...str].reverse().join('');
*/
