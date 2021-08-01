#ifndef __BVH_H__
#define __BVH_H__

namespace Physicc
{
	struct BVHNode
	{

	};

	class BVH
	{
		public:
			BVH();

			void buildTree();
			//build a tree of the bounding volumes

			std::vector<rididbody>& convert();
			//convert the tree into a linear data structure

		private:
			BVHNode* m_head;
	};
}

#endif //__BVH_H__
