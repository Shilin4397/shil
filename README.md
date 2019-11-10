# shil
 //返回两个链表的交点
    public static Listnode getIntersectionNode (Listnode headA,Listnode headB){
        if(headA == null || headB == null) {
            return null;
        }
        //永远指向最长的单链表
        Listnode pL = headA;
        //永远指向最短的单链表
        Listnode pS = headB;
        int lenA = 0;
        int lenB = 0;
        //分别求长度
        while(pL!=null){
            pL=pL.next;
            lenA++;
        }
        while(pS!=null) {
            pS=pS.next;
            lenB++;
        }
        //求长度的差值
        int len = lenA-lenB;
        //如果是负数-》pL = headB;  pS = headA
        if(len>0) {
            pL=headA;
            pS=headB;
        }else {
            len=-len;
            pL=headB;
            pS=headA;
        }
        //只需要让pL走len步就好了
        while(len>0) {
            pL=pL.next;
            len--;
        }
        //走完len步之后  两个同时开始走
        //一直走 走到next值相同时 就是交点
        while(pL!=pS && pL!=null) {
            pL = pL.next;
            pS = pS.next;
        }
        if(pL==pS && pL!=null) {
            return pL;
        }
        return null;
    }
