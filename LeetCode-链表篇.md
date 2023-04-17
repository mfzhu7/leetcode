# LeetCode-链表篇

[toc]



## LeetCode2 

[两数相加](https://leetcode.cn/problems/add-two-numbers/)

**题干** 

给你两个 **非空** 的链表，表示两个非负的整数。它们每位数字都是按照 **逆序** 的方式存储的，并且每个节点只能存储 **一位** 数字。

请你将两个数相加，并以相同形式返回一个表示和的链表。

你可以假设除了数字 0 之外，这两个数都不会以 0 开头。

![img](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2021/01/02/addtwonumber1.jpg)


**样例如下**

```c++
输入：l1 = [2,4,3], l2 = [5,6,4]
输出：[7,0,8]
解释：342 + 465 = 807.
```



**题解思路**

- 新建虚拟头结点，方便处理链表为空的情况
- carry记录进位情况，l1_val和l2_val分别记录遍历不同链表的值
- 注意循环终止条件为：两个链表均为空的情况下
- 注意跳出循环后，需要判断是否有进位存在

**代码**

```c++
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* n1 = l1;
        ListNode* n2 = l2;
        ListNode* dummy = new ListNode(-1); //虚拟头节点的处理
        ListNode* temp = dummy;
        int carry = 0;
        int l1_val = 0;
        int l2_val = 0;
        while(n1 || n2){
            l1_val = n1?n1->val:0;
            l2_val = n2?n2->val:0;
            ListNode* tmp = new ListNode((l1_val+l2_val+carry) % 10);
            carry = (l1_val+l2_val+carry) / 10; //进位的处理
            temp->next = tmp;
            temp = temp->next;
            n1 = n1?n1->next:n1;
            n2 = n2?n2->next:n2;
        }
        if (carry){
            ListNode* tmp = new ListNode(1);
            temp->next = tmp;
            return dummy->next;
        }else {
            return dummy->next; //最后是否进位的判断
        }
    
    }
};
```





## LeetCode19

[删除链表的倒数第 N 个结点](https://leetcode.cn/problems/remove-nth-node-from-end-of-list/)

**题干** 

给你一个链表，删除链表的倒数第 `n` 个结点，并且返回链表的头结点。

![img](https://assets.leetcode.com/uploads/2020/10/03/remove_ex1.jpg)

**样例如下**

```cpp
输入：head = [1,2,3,4,5], n = 2
输出：[1,2,3,5]
```


**题解思路**

- 核心解题思路在于找到待删除的前一个节点和后一个节点
- 利用快慢双指针，先让快指针走n-1步；然后快慢指针同时开始遍历
- 直到快指针到达末尾即可停止，此时慢指针即为待删除指针的前一个节点
- 虚拟头结点的设置用于要删除链表第一个节点的情况



**代码**


```c++
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* first = dummy;
        ListNode* second = dummy->next;
        //注意虚拟节点的设置
        while(n - 1 > 0){
            second = second->next;
            n = n - 1;
        } //快慢指针写法，快指针先走n-1步
        while(second->next){
            second = second->next;
            first = first->next;
        }//快慢指针同时走，直到快指针到对尾巴
        first->next = first->next->next;
        //改变节点连接
        return dummy->next;
        //返回头结点

    }
};
```



```
堆解法待实现
```









## LeetCode21 

[合并两个有序链表](https://leetcode.cn/problems/merge-two-sorted-lists/)

**题干**

将两个升序链表合并为一个新的 **升序** 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

![img](https://assets.leetcode.com/uploads/2020/10/03/merge_ex1.jpg)

**样例如下**

```c++
输入：l1 = [1,2,4], l2 = [1,3,4]
输出：[1,1,2,3,4,4]
```


**解题思路**

- 设定头节点为两个链表中较小的那个(curr1)，分别用curr1和curr2记录遍历过程中两个链表的节点
- 如果curr1的**下一个节点**数据大于curr2，此时要把curr2插入到curr1后面
- 在跳出循环后，需要判断curr2是否为空；不为空的话，把curr2接在curr1后
- 注意点在于：以curr1为标杆，需要保存curr1和curr1->next的节点

**代码**

```cpp
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1 || !list2) return list1?list1:list2; //判空处理
        ListNode* res = list1->val > list2->val ? list2 : list1;
        //保存头结点，把数据保存在头结点较小的链表中
        ListNode* curr1 = res; 
        ListNode* curr2 = list1->val > list2->val ? list1:list2;
		//遍历过程的2个链表的指针
        while(curr1 && curr1->next && curr2){
            //保证curr1和curr1的下一个节点不为空
            if (curr1->next->val >= curr2->val){
                //如果curr1的下一个节点的数值较大，即curr2要插入其中
                ListNode* temp = curr1->next;
                //记录curr1的下一个节点
                curr1->next = curr2;
                //重新指向curr1->next
                curr2 = curr2->next;
               	//curr2进行移动
                curr1->next->next = temp;
                //curr1的next的next节点进行移动
                curr1 = curr1->next;
                //curr1移动
            } else {
                curr1 = curr1->next;
            }
        }
        if (curr2){
            curr1->next = curr2; //需要判断curr2是否已经结束
        }
        return res;
    }
};

//递归写法
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) {
            return l2;
        } else if (l2 == nullptr) {
            return l1;
        } else if (l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};


```



```
遍历的优化版本待实现
```





## LeetCode24



[两两交换链表中的节点](https://leetcode.cn/problems/swap-nodes-in-pairs/)

**题干**

给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。你必须在不修改节点内部的值的情况下完成本题（即，只能进行节点交换）。

![img](https://assets.leetcode.com/uploads/2020/10/03/swap_ex1.jpg)

**样例**

```c++
输入：head = [1,2,3,4]
输出：[2,1,4,3]
```


**题解思路**

- 本题主要的点在于记录前置节点，方便进行交换操作
- 首先记录下curr->next节点2；而后curr指向了curr->next->next节点3
- 然后前置节点的next指向了2，节点2的next指向了curr(节点1)
- 前置节点prev此时变更为curr(节点1)，curr节点变更为3

**代码**

```cpp
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;//判空处理
        ListNode* dummy = new ListNode(-1);
        dummy->next = head; //虚拟节点设置
        ListNode* pre = dummy;
        ListNode* curr = dummy->next; //设置先后节点

        while(curr && curr->next) {
            ListNode* temp = curr->next;
            curr->next = curr->next->next;
            pre->next = temp;
            temp->next = curr;
            pre = curr; //节点变更操作，主要在于要有prev节点的记录，便于链表进行操作
            curr = curr->next;
        }
        return dummy->next;
    }
};

//递归的官方解法
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* newHead = head->next;
        head->next = swapPairs(newHead->next);
        newHead->next = head;
        return newHead;
    }
};

```







## LeetCode61 

[旋转链表](https://leetcode.cn/problems/rotate-list/)

**题干** 

给你一个链表的头节点 `head` ，旋转链表，将链表每个节点向右移动 `k` 个位置。



![img](https://assets.leetcode.com/uploads/2020/11/13/rotate1.jpg)



**样例**

```c++
输入：head = [1,2,3,4,5], k = 2
输出：[4,5,1,2,3]
```

**解题思路** 

- 首先需要注意，k可能超过链表的长度
- 计算链表的长度，求余得到新的移动位置数量
- **将尾部节点和头节点连接，构成环** 
- 遍历链表找到断开位置，重新链接链表

**代码**

```c++
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head||!head->next) return head;
        ListNode* curr = head;
        int length = 1;
        while(curr->next){
            length += 1;
            curr = curr->next;
        } // 计算链表长度，为了求余k
        curr->next = head; //链表末尾连接头部
        k = length -  k % length;
        curr = head;
        while(k > 1){
            curr = curr->next;
            k = k - 1;
        }  //找到位置断开
        ListNode* res = curr->next;
        curr->next = nullptr;
        return res;

    }
};
```







## LeetCode82

[删除排序链表中的重复元素 II](https://leetcode.cn/problems/remove-duplicates-from-sorted-list-ii/)

**题干**

给定一个已排序的链表的头 `head` ， *删除原始链表中所有重复数字的节点，只留下不同的数字* 。返回 *已排序的链表* 。

![img](https://assets.leetcode.com/uploads/2021/01/04/linkedlist1.jpg)







**样例**

```c++
输入：head = [1,2,3,3,4,4,5]
输出：[1,2,5]
```



**解题思路** 

- 虚拟头节点设置用于要删除头结点的情况
- 虚拟头结点刚好作为前置节点pre，**注意遍历终止条件设置**
- 如果存在相同节点，不断向后遍历直到新节点出现
- 前置节点重现修改next指针

```c++
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* dummy = new ListNode(-1000);
        dummy->next = head; //创建虚拟头节点
        ListNode* pre = dummy;
        ListNode* curr = head;
        while(curr && curr->next){
            //边界条件的设置
            if (curr->val == curr->next->val){
                int temp = curr->val;
                while(curr && curr->val == temp){
                    curr = curr->next;
                    // 如果存在相同的，一直遍历到最后一个，然后进行更改节点
                }
                pre->next = curr;
            } else {
                pre = pre->next;
                curr = curr->next;
                //不相同的情况的处理
            }
        }
        return dummy->next;

    }
};
```



## LeetCode83

[删除排序链表中的重复元素](https://leetcode.cn/problems/remove-duplicates-from-sorted-list/)

> 链表操作

```c++
输入：head = [1,1,2,3,3]
输出：[1,2,3]
```



```c++
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* pre = head;
        ListNode* curr = head->next;
        while(curr){
            if (pre->val == curr->val){
                pre->next = curr->next;
                curr = curr->next;
            } else {
                pre = pre->next;
                curr = curr->next;
            }
        }
        return head;
        //同上一题，相同做法。
    }
};
```

## LeetCode86(待完善新的做法)

[分割链表](https://leetcode.cn/problems/partition-list/)

> 链表操作

```c++
输入：head = [1,4,3,2,5,2], x = 3
输出：[1,2,2,4,3,5]
```

```c++
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (!head || !head->next) return head;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head; //虚拟头结点设置
        ListNode* pre = dummy;
        ListNode* next = pre->next; //先后节点设置
        while(next && next->val < x){
            next = next->next;
            pre = pre->next;
        } //找到第一个大于x的链表节点
        if (!next) return head;
        while(next->next){
            if (next->next->val >= x){
                next = next->next;
            }else {
                ListNode* temp1 = next->next;
                next->next = temp1->next;
                ListNode* temp2 = pre->next;
                pre->next = temp1;
                temp1->next = temp2;
                pre = pre->next;
            }
        }
        return dummy->next;

    }
};
```

## LeetCode(还有头插法待实现)

[反转链表 II](https://leetcode.cn/problems/reverse-linked-list-ii/)

> 链表操作

```c++
输入：head = [1,2,3,4,5], left = 2, right = 4
输出：[1,4,3,2,5]
```



```c++
class Solution {
public:
    void reverseList(ListNode* head){
        ListNode* pre = nullptr;
        ListNode* curr = head;
        while(curr){
            ListNode* next = curr->next;
            curr->next = pre;
            pre = curr;
            curr = next;
        }
    } // 反转链表
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        
        ListNode* curr = dummy;
        ListNode* leftNode = nullptr;
        ListNode* rightNode = nullptr;
        for (int i = 1;i < left; i++){
            curr = curr->next;
        }
        leftNode = curr; //找到左节点
        for (int j = 0; j < right - left + 1; j++){
            curr = curr->next;
        }
        rightNode = curr; //找到右节点

        ListNode* r_left = leftNode->next;
        ListNode* r_right = rightNode->next;

        leftNode->next = nullptr;
        rightNode->next = nullptr;
		//记录节点并且断开
        
        reverseList(r_left); // 反转链表

        leftNode->next = rightNode;
        r_left->next = r_right;
        return dummy->next; // 重新连接
    }
};
```



## LeetCode138 

[复制带随机指针的链表](https://leetcode.cn/problems/copy-list-with-random-pointer/)

![img](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/01/09/e1.png)

```c++
输入：head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
输出：[[7,null],[13,0],[11,4],[10,2],[1,0]]
```



```c++
class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* h1 = head;
        unordered_map<Node*, Node*> hash;
        while(h1){
            Node* temp = new Node(h1->val);
            hash.insert({h1,temp});
            h1 = h1->next;
            //将新老节点之间的关系设定为字典，方便查询和链表重连接
        }
        h1 = head;
        while(h1){
            hash[h1]->next = hash[h1->next];
            hash[h1]->random = hash[h1->random];
            h1 = h1->next;
        }
        return hash[head];
    }
};
```



## LeetCode141

[环形链表](https://leetcode.cn/problems/linked-list-cycle/)

> 快慢指针判断是否存在环

```c++
输入：head = [3,2,0,-4], pos = 1
输出：true
解释：链表中有一个环，其尾部连接到第二个节点。
```

```cpp
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head || !head->next) return false;
        ListNode* fast = head->next;
        ListNode* slow = head;
        while(fast && fast->next&& slow){
            if (fast == slow) {return true;}
            else {
                fast = fast->next;
                fast = fast->next;
                slow = slow->next;
            }
        }
        return false;
        
    }
};
```



## LeetCode142

[环形链表 II](https://leetcode.cn/problems/linked-list-cycle-ii/)

> 快慢指针定位入环位置



```c++
输入：head = [3,2,0,-4], pos = 1
输出：返回索引为 1 的链表节点
解释：链表中有一个环，其尾部连接到第二个节点。
```



```c++
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head || !head->next) return nullptr;
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast){
            slow = slow->next;
            if (!fast->next){
                return nullptr;
            }
            fast = fast->next->next;

            if (slow == fast){
                ListNode* ptr = head;
                while(ptr != fast){
                    ptr = ptr->next;
                    fast = fast->next;
                }
                return ptr;
            }
        }
        return nullptr;
        
    }
};
```



## LeetCode143

[重排链表](https://leetcode.cn/problems/reorder-list/description/)

给定一个单链表 `L` 的头节点 `head` ，单链表 `L` 表示为：

```
L0 → L1 → … → Ln - 1 → Ln
```

请将其重新排列后变为：

```
L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
```

不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。



```c++
class Solution {
public:
    ListNode* reverse(ListNode* head){
        ListNode* pre = nullptr;
        ListNode* curr = head;
        while(curr){
            ListNode* next = curr->next;
            curr->next = pre;
            pre = curr;
            curr = next;
        } 
        return pre;
        //辅助函数，用来反转链表
    }
    void reorderList(ListNode* head) {
        ListNode* curr = head;
        int length = 1;
        while(curr){
            length += 1;
            curr = curr->next;
        }
        int mid = length / 2;
        curr = head;
        while(mid > 1){
            curr = curr->next;
            mid = mid - 1;
        }   //找到中间节点
        ListNode* leftHead = curr->next;
        curr->next = nullptr;
        leftHead = reverse(leftHead);
        //断开连接，反转后半部分链表

        curr = head;
        while(leftHead){
            ListNode* next1 = curr->next; 
            ListNode* next2 = leftHead->next;
            curr->next = leftHead;
            leftHead->next = next1;
            curr = next1;
            leftHead = next2;
        } //链表重新连接
        return;


    }
};
```



## LeetCode148（o1写法待完善）

[排序链表](https://leetcode.cn/problems/sort-list/)

> 链表+排序

给你链表的头结点 `head` ，请将其按 **升序** 排列并返回 **排序后的链表** 。

```c++
输入：head = [4,2,1,3]
输出：[1,2,3,4]
```

```c++
class Solution {
public:
    ListNode* sortList(ListNode* head, ListNode* tail){
        if(!head) return head;
        if (head->next == tail){
            head->next = nullptr;
            return head;
        }
        ListNode* fast = head, *slow = head;
        while(fast != tail){
            fast = fast->next;
            slow = slow->next;
            if (fast != tail){
                fast = fast->next;
            }
        }
        ListNode* mid = slow;
        return merge(sortList(head,mid), sortList(mid,tail));

    }
    ListNode* merge(ListNode* left, ListNode* right){
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        ListNode* temp1 = left;
        ListNode* temp2 = right;
        while(temp1 && temp2){
            if (temp1->val < temp2->val){
                temp->next = temp1;
                temp1 = temp1->next;
            } else {
                temp->next = temp2;
                temp2 = temp2->next;
            }
            temp = temp->next;
        }
        if (temp1){
            temp->next = temp1;
        } else if (temp2){
            temp->next = temp2;
        }
        return dummy->next;
    }
    ListNode* sortList(ListNode* head) {
        return sortList(head,nullptr);
    }
};
```



## LeetCode160

[相交链表](https://leetcode.cn/problems/intersection-of-two-linked-lists/)

> 链表+指针



![img](https://assets.leetcode.com/uploads/2021/03/05/160_example_1_1.png)

```c++
输入：intersectVal = 8, listA = [4,1,8,4,5], listB = [5,6,1,8,4,5], skipA = 2, skipB = 3
输出：Intersected at '8'
解释：相交节点的值为 8 （注意，如果两个链表相交则不能为 0）。
从各自的表头开始算起，链表 A 为 [4,1,8,4,5]，链表 B 为 [5,6,1,8,4,5]。
在 A 中，相交节点前有 2 个节点；在 B 中，相交节点前有 3 个节点。
— 请注意相交节点的值不为 1，因为在链表 A 和链表 B 之中值为 1 的节点 (A 中第二个节点和 B 中第三个节点) 是不同的节点。换句话说，它们在内存中指向两个不同的位置，而链表 A 和链表 B 中值为 8 的节点 (A 中第三个节点，B 中第四个节点) 在内存中指向相同的位置。
```



```c++
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lengthA = 0;
        int lengthB = 0;
        ListNode* curr = headA;
        while(curr){
            lengthA += 1;
            curr = curr->next;
        } //计算a的长度
        curr = headB;
        while(curr){
            lengthB += 1;
            curr = curr->next;
        } //计算b的长度
        int diff = lengthA > lengthB ? lengthA - lengthB : lengthB - lengthA;
		//找到diff
        curr = lengthA > lengthB ? headA : headB;
        ListNode* other = (lengthA > lengthB) ? headB: headA;
		//找到较长的那个头节点
        while(diff){
            curr = curr->next;
            diff = diff - 1;
        } //让其中一个指针先走diff步
        while(curr){
            if (curr == other){
                return curr;
                //相遇了即为相交节点
            } else {
                curr = curr->next;
                other = other->next;
            }
        }
        return nullptr;
        
    }
};
```



## LeetCode203

> 链表注意虚拟头节点的创建

![img](https://assets.leetcode.com/uploads/2021/03/06/removelinked-list.jpg)

```c++
输入：head = [1,2,6,3,4,5,6], val = 6
输出：[1,2,3,4,5]
```

```c++
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (head == nullptr) {return head;}
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        ListNode* temp = dummy;
        while(temp->next != nullptr){
            if(temp->next->val == val){
                temp->next = temp->next->next;
            } else{
                temp = temp->next;
            }
        }
        return dummy->next;

    }
};
```



## LeetCode206

[反转链表](https://leetcode.cn/problems/reverse-linked-list/)





![img](https://assets.leetcode.com/uploads/2021/02/19/rev1ex1.jpg)



```c++
输入：head = [1,2,3,4,5]
输出：[5,4,3,2,1]
```



```c++
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head) return head;
        ListNode* prev(0);
        ListNode* curr = head;
        while(curr){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;

    }
};
```



## LeetCode234

[回文链表](https://leetcode.cn/problems/palindrome-linked-list/)



```c++
输入：head = [1,2,2,1]
输出：true
```



```c++
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> vec;
        while(head){
            vec.push_back(head->val);
            head = head->next;
        }
        int left = 0;
        int right = vec.size() - 1;
        while(left < right){
            if (vec[left] != vec[right]) return false;
            left = left + 1;
            right = right - 1;
        }
        return true;

    }
};
```



## LeetCode237

[ 删除链表中的节点](https://leetcode.cn/problems/delete-node-in-a-linked-list/)

```c++
输入：head = [4,5,1,9], node = 5
输出：[4,1,9]
解释：指定链表中值为 5 的第二个节点，那么在调用了你的函数之后，该链表应变为 4 -> 1 -> 9
```



```c++
class Solution {
public:
    void deleteNode(ListNode* node) {
        while(node->next){
            if (node->next->next == nullptr){
                node->val = node->next->val;
                node->next = nullptr;
                break;

            } else {
                node->val = node->next->val;
                node = node->next;
            }
        }
        return;
    }
};
```



## LeetCode328

[奇偶链表](https://leetcode.cn/problems/odd-even-linked-list/)

```c++
输入: head = [2,1,3,5,6,4,7]
输出: [2,3,6,7,1,5,4]
```



```c++
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head) return head;
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* eventHead = even;
        while(even && even->next){
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        odd->next = eventHead;
        return head;

    }
};
```

