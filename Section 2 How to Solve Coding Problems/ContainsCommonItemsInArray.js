// Given 2 arrays, create a function that let's a user know (true/false) whether these two arrays contain any common items
//For Example:
//const array1 = ['a', 'b', 'c', 'x'];//const array2 = ['z', 'y', 'i'];
//should return false.
//-----------
//const array1 = ['a', 'b', 'c', 'x'];//const array2 = ['z', 'y', 'x'];
//should return true.

// 2 parameters - arrays - no size limit
// return true or false


const array1 = ['a', 'b', 'c', 'x'];
const array2 = ['z', 'y', 'x'];

//O(a*b) quadratic solution
//O(1) space complexity
// function containsCommonItem(arr1, arr2){
//   for(let i=0; i<arr1.length; i++){
//     for(let j=0; j<arr2.length; j++){
//       if(arr1[i] === arr2[j]){
//         return true;
//       }
//     }
//   }
//   return false;
// }


//O(a+b) - Time Complexity
//O(a) - Space Complexity
function containsCommonItem(arr1, arr2){
  //loop through first array and create object where properties equal items in the array
  let map={};
  for(let i=0; i<arr1.length; i++){
    //If arr[i] not in map
    if(!map[arr1[i]]){
      const item = arr1[i];
      map[item] = true;
    }
  }
  console.log(map);
  //to loop through second array and check if item in second array exists in created object
  for(let j=0; j<arr2.length; j++){
    if(map[arr2[j]]){
      return true;
    }
  }
  return false;
}

//Method 3, using inbuilt linear, Language Specific Solution
function containsCommonItem3(arr1, arr2) {
  return arr1.some(item => arr2.includes(item))
}


containsCommonItem(array1, array2);
