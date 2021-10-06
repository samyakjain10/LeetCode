<h2>141. Linked List Cycle</h2>
<h3>Easy</h3>
<hr>
Given head, the <code>head</code> of a linked list, determine if the linked list has a cycle in it.
<hr>
<div>
<p>There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the <code>next</code> pointer. Internally, <code>pos</code> is used to denote the index of the node that tail's next pointer is connected to. <b>Note that <code>pos</code> is not passed as a parameter.</b>

Return <code>true</code> <em>if there is a cycle in the linked list.</em> Otherwise, return <code>false</code>.

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2018/12/07/circularlinkedlist.png" style="width: 324px; height: 202px;">
<pre>
<strong>Input:</strong> head = [3,2,0,-4], pos = 1
<strong>Output:</strong> true
<strong>Explanation:</strong> There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2018/12/07/circularlinkedlist_test2.png" style="width: 324px; height: 202px;">
<pre>
<strong>Input:</strong> head = [1,2], pos = 0
<strong>Output:</strong> true
<strong>Explanation:</strong> There is a cycle in the linked list, where the tail connects to the 0th node.
</pre>

<p><strong>Example 3:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2018/12/07/circularlinkedlist_test3.png" style="width: 202px; height: 202px;">
<pre>
<strong>Input:</strong> head = [1], pos = -1
<strong>Output:</strong> false
<strong>Explanation:</strong> There is no cycle in the linked list.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the tree is in the range <code>[0, 10000]</code>.</li>
	<li><code>-100000 &lt;= Node.val &lt;= 100000</code></li>
	<li><code>pos</code> is <code>-1</code> or a <b>valid index</b> in the linked-list.</li>
</ul>

<p>&nbsp;</p>
<strong>Follow up:</strong> Can you solve it using <code>O(1)</code> (i.e. constant) memory?</div>
