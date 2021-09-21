//Function to merge 2 arrays and sort them
function mergeSortedArrays(arr1, arr2){
  const array = [];
  let array1Item = arr1[0];
  let array2Item = arr2[0];
  let i=1;
  let j=1;

  if(arr1.length===0){
    return arr2;
  }
  if(arr2.length===0){
    return arr1;
  }
  
  while(array1Item || array2Item){
    if(array2Item === undefined || array1Item<array2Item){
      array.push(array1Item);
      array1Item = arr1[i];
      i++;
    }
    else{
      array.push(array2Item);
      array2Item = arr2[j];
      j++;
    }
  }
  return array;
}


mergeSortedArrays([0,3,4,31], [3,4,6,30]);
/* 
Output:
[
 0,3,3,4
 4,6,30,31
]
*/
