#ifndef NODE_H
#define NODE_H
template <class T> class Node { //Creates a Node of a data structure
	public:
		Node() {
			this->id = -1;
		}
		Node(int id) {
			this->id = id;
		};

		int id;
		T neighbors;

		//Overload of various important operators
		bool operator==(Node& target) {
			return id == target.id;
		};
		bool operator==(int target) {
			return id == target;
		};
		bool operator!=(Node& target) {
			return id != target.id;
		}
		bool operator!=(int target) {
			return id != target;
		}
		bool operator<(Node& target) {
			return id < target.id;
		}
		bool operator<(int target) {
			return id < target;
		}
		bool operator>(Node& target) {
			return id > target.id;
		}
		bool operator>(int target) {
			return id > target;
		}
		int operator%(int target) {
			return id % target;
		}
		//Helper Variable for DFS
		bool visited;
};

#endif // NODE_H
