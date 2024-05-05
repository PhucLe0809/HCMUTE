	Đây là bộ code về các giải thuật (Algorithm) trong Lý thuyết đồ thị (Graph Theory) được tham khảo từ nhiều nguồn, trong đó có 2 nguồn chính: 
		1. 2 quyển SGK chuyên Tin (quyển 1 & quyển 2) do PGS.TS.NGND Hồ Sĩ Đàm Tổng chủ biên.
		2. Trang VNOI Wiki - trang Tài liệu học thuật Lập trình thi đấu (Competitive Programming) lớn nhất Việt Nam.
	Các giải thuật được trình bày bao gồm:
		1. Graph Traversal: DFS (Depth-First-Search) & BFS (Breath-First-Search)
		2. Shortest Path: Dijkstra Algorithm.
		3. Spanning Tree: Prim Algorithm & Kruskal Algorithm.
		4. Euler Circuit & Hamilton Circuit.
		5. Strongly Connected Components: Tarjan Algorithm & Kosaraju Sharir Algorithm.
	Trong Graph Theory vẫn còn khá nhiều vấn đề mà ta chưa đề cập đến ở đây như: 
		1. Bài toán đếm số Thành phần liên thông của 1 đồ thị vô hướng không trọng số, khôn khuyên (Ứng dụng DFS & BFS)
		2. Bài toán tìm đường đi ngắn nhất trên đồ thị vô hướng không trọng số, không khuyên (BFS kết hợp Backtracking)
		3. Bài toán liệt kê khớp (points) và cầu (bridges) của đồ thị vô hướng không trọng số, không khuyên.
		4. Đồ thị song liên thông.
		5. Khử đệ quy DFS bằng Stack.
		6. DSU-Disjoint Set Union.
	Bên trên là các nội dung gợi ý mà các bạn có thể tham khảo thêm.
	***Lưu ý: Tất cả các giải thuật bên dưới đây có chỉ số đỉnh luôn bắt đầu từ 1 -> n.

=== Trong quá trình học tập luôn khó tránh khỏi những sai sót. Nếu phát hiện lỗi, bạn có thể liên hệ với mình để cùng nhau thảo luận thêm!

	Sau đây là testcase cho các giải thuật:
===DFS and BFS:
10 10 1
1 5
1 10
2 10
2 4
3 6
4 5
5 2
7 8
8 9
9 7

===Dijkstra Algorithm:
7 8 1
1 3 7
1 2 1
1 4 4
3 6 8
6 4 3
5 6 6
2 5 3
3 5 3

===Prim and Kruskal Algorithm:
7 8 1
1 3 7
1 2 1
1 4 4
3 6 8
6 4 3
5 6 6
2 5 3
3 5 3

===Euler circuit and Hamilton circuit:
8 12
4 7
4 3
4 8
4 1
3 7
1 8
2 3
2 1
2 6
2 5
3 6
1 5

===Tarjan Algorithm and Kosaraju Sharir Alogrithm:
11 15 
1 2 
1 8 
2 3 
3 4 
4 2 
4 5 
5 6 
6 7 
7 5 
8 9 
9 4 
9 10 
10 8 
10 11 
11 8
