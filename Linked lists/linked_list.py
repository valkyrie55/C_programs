class node:
    def __init__(self, data):
        self.data = data
        self.next = None

class linkedlist:
    def __init__(self):
        self.head = None

    def push(self, data):
        new_node = node(data)
        new_node.next = self.head
        self.head = new_node

    def display(self):
        temp = self.head
        while(temp):
            print(temp.data)
            temp = temp.next


if __name__ == '__main__' :
    #create an empty linked list
    llist = linkedlist()
    #assign value to head
    llist.head = node(1)
    second = node(2)
    third = node(3)
    llist.head.next = second;
    second.next = third;
    #traverse
    # add some more nodes
    llist.push(10)
    llist.push(20)
