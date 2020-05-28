using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class WeekThree : MonoBehaviour {

    public GameObject mSphere;
    public float radius = 80;
    public int numbers = 1000;

    private List<Vector2> posList = new List<Vector2>();
    private List<Vector2> posList2 = new List<Vector2>();
    //private List<GameObject> sphereList = new List<GameObject>();

    private float closestDistance;
    private float dis;//最短点对函数中记录左右两侧中更短的距离
    //private int indexL, indexR;//记录最近两个点在数组中的下标

    private Vector2 position;
    private Quaternion q = new Quaternion(0, 0, 0, 0);

	// Use this for initialization
	void Start () {
        //范围内生成小球
        for (int i = 0; i < numbers; i++)
        {
            position = Random.insideUnitCircle * radius;
            posList.Add(position);
            GameObject Sphere = Instantiate(mSphere, position, q);
            Sphere.name = "sphere" + i;
            //sphereList.Add(Sphere);
        }
        //销毁碰撞的小球坐标,Oncollision的执行顺序在Start之后，以下代码功能未实现
        /*for (int i = 0; i < numbers; i++)
        {
            bool isdestroy = sphereList[i].GetComponent<DestroySphere>().getIsDestroy();
            if(isdestroy)
            {
                //sphereList.RemoveAt(i);
                posList.RemoveAt(i);
            }
        }
        Debug.Log("posList长度"+posList.Count);*/
        posList.Sort((a, b) => a.x.CompareTo(b.x));//posList按x轴升序排序

        closestDistance = ClosestPairOfPoints(posList,0,posList.Count-1);//调用函数
	}

    void OnGUI()
    {
        GUI.Label(new Rect(100, 100, 200, 100), "<color=#00ff00><size=30>" + closestDistance.ToString() + "</size></color>");
        //GUI.Label(new Rect(100, 200, 200, 100), "<color=#ff0000><size=30>" + "( "+indexL+" , "+indexR+" )" + "</size></color>");
    }

    float ClosestPairOfPoints(List<Vector2> list,int left,int right)
    {//分治法求最短点对
        if ((right - left) == 1)
        {
            float d = Distance(list[left], list[right]);
            if (d > 2)
                return d;
            else
                return 999.999f;
        }
        if(right==left)
        {
            return 999.999f;
        }
        int mid = (right + left) / 2;
        dis = Mathf.Min(ClosestPairOfPoints(list, left, mid), ClosestPairOfPoints(list, mid + 1, right));

        //[mid-dis,mid+dis]y轴排序
        posList2.Clear();
        int minList2 = (int)Mathf.Min(mid + dis, right);
        for (int i = 0; i < minList2; i++)
        {
            if ((mid - i) < dis && (mid - i) > -dis)
            {
                posList2.Add(posList[i]);
            }
        }
        posList2.Sort((a, b) => a.y.CompareTo(b.y));
        for(int i=0;i<posList2.Count; i++)
        {
            for(int j=i+1;j<posList2.Count;j++)
            {
                float D = posList2[j].y - posList2[i].y;
                if (D >= dis || Distance(posList2[i], posList2[j]) < 2)
                {
                    break;
                }
                else
                {
                    dis = Mathf.Min(dis, Distance(posList2[i], posList2[j]));
                }
            }
        }
        return dis;
    }

    float Distance(Vector2 a,Vector2 b)
    {//返回两点间距离
        return (b - a).magnitude;
    }

}
