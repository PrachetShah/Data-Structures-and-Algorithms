// Create the below linked list:
// myLinkedList = {
//   head: {
//     value: 10
//     next: {
//       value: 5
//       next: {
//         value: 16
//         next: null
//       }
//     }
//   }
// };

class LinkedList {
  constructor(value){
    this.head = {
      value: value,
      next: null
    };
    this.tail = this.head;
    this.length = 1;
  }

  append(value){
    //code
    const newNode = {
      value: value,
      next: null
    };
    this.tail.next = newNode;
    this.tail = newNode;
    this.length += 1;
    return this
  }

  prepend(value){
    //code
    const newNode = {
      value: value,
      //We keep this null here instead of this.head to avoid memory loss
      next: null
    };
    newNode.next = this.head;
    this.head = newNode;
    this.length += 1;
    return this
  }

  printList(){
    const array = [];
    let currentNode = this.head
    while(currentNode !== null){
      array.push(currentNode.value);
      currentNode = currentNode.next;
    }
    return array;
  }
}

let myLinkedList = new LinkedList(10);
myLinkedList.append(5);
myLinkedList.append(16);
myLinkedList.prepend(1)
myLinkedList.printList()



//Output: [1,10,5,16]
