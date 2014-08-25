using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MoreCodingCSharp
{

    class RedBlackTreeNode
    {
        RedBlackTreeNode _parent;

        public RedBlackTreeNode Parent
        {
            get { return _parent; }
            set { _parent = value; }
        }

        RedBlackTreeNode _leftNode;

        public RedBlackTreeNode LeftNode
        {
            get { return _leftNode; }
            set { _leftNode = value; }
        }

        RedBlackTreeNode _rightNode;

        public RedBlackTreeNode RightNode
        {
            get { return _rightNode; }
            set { _rightNode = value; }
        }

        bool _isBlack;
        public bool IsBlack
        {
            get { return _isBlack; }
            set { _isBlack = value; }
        }
        int _data;

	    public int Data
	    {
		    get { return _data; }
	    }

        public RedBlackTreeNode( int data )
        {
            _data = data;
            _isBlack = true;
            RightNode = null;
            LeftNode = null;
        }


    }
    class RedBlackTree
    {

        RedBlackTreeNode _root;
        public MoreCodingCSharp.RedBlackTreeNode Root
        {
            get { return _root; }
        }

        public RedBlackTree()
        {
            _root = null;
        }

        public void Insert( int data )
        {
            RedBlackTreeNode node = new RedBlackTreeNode( data );

            //case 1
            if (Root == null)
            {
                _root = node;
                node.IsBlack = true;
                
                return;
            }
            
            RedBlackTreeNode currentNode = _root;

            while (true)
            {
                if (data < currentNode.Data)
                {
                    currentNode = currentNode.LeftNode;
                }
                
            }
        }
    }
}

