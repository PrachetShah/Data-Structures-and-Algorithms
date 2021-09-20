const strings= ['a', 'b', 'c', 'd'];
const numbers = [1,2,3,4,5];
// Variable array is somewhere in memory and the computer knows it.
// When I do array[2], i'm telling the computer, hey go to the array and grab the 3rd item from where the array is stored.


//push
strings.push('e');
console.log(strings);
//pop
strings.pop();
console.log(strings);
strings.pop();
console.log(strings);

//unshift
strings.unshift('x')
console.log(strings);

//splice 
//Second parameter is no of elements to remove after it
strings.splice(2, 0, 'alien');
console.log(strings);

strings.splice(3, 2, 'alien');
console.log(strings);

/* Output:
['a', 'b', 'c', 'd','e']
['a', 'b', 'c', 'd']
['a', 'b', 'c']
['x','a', 'b', 'c']
['x','a','alien','b', 'c']
['x','a','alien','alien']
*/
