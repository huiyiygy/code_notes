# -*- coding:utf-8 -*-


class ListNode:
    """
    Definition for singly-linked list.
    """
    def __init__(self, x):
        self.val = x
        self.next = None


def addTwoNumbers(l1: ListNode, l2: ListNode) -> ListNode:
    result = ListNode(0)
    res_next = result
    carry = 0
    while True:
        a = l1.val if l1 else 0
        b = l2.val if l1 else 0
        var = a + b + carry
        if var >= 10:
            var = var % 10
            carry = 1
        else:
            carry = 0
        res_next.next = ListNode(var)
        res_next = res_next.next
        l1 = l1.next if l1 else None
        l2 = l2.next if l2 else None
        if l1 is None and carry == 0:
            res_next.next = l2
            break
        if l2 is None and carry == 0:
            res_next.next = l1
            break
    return result.next


if __name__ == "__main__":
    # 构造两个链表
    nums1 = [2, 4, 3]
    nums2 = [5, 6, 4]
    l1 = ListNode(0)  # 表头
    l2 = ListNode(0)
    l1_next = l1  # 尾指针
    l2_next = l2
    for i in range(3):
        l1_next.next = ListNode(nums1[i])
        l1_next = l1_next.next
        l2_next.next = ListNode(nums2[i])
        l2_next = l2_next.next
    l1 = l1.next
    l2 = l2.next

    result = addTwoNumbers(l1, l2)
    while result:
        print(result.val)
        result = result.next

