using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class SphereMove : MonoBehaviour {

    public float radius = 10;
    public float moveSpeed = 5;

    public GameObject sphere1;
    public GameObject sphere2;

    private Vector3 newPosition1;
    private Vector3 newPosition2;
    private float distance;

    // Use this for initialization
    void Start () {
        newPosition1 = Random.insideUnitSphere * radius;
        newPosition2 = Random.insideUnitSphere * radius;
    }

    // Update is called once per frame
    void Update() {

        Debug.DrawLine(sphere1.transform.position, sphere2.transform.position, Color.green);
        distance = (sphere1.transform.position - sphere2.transform.position).magnitude;
        Debug.Log(distance);

        if (sphere1.transform.localPosition == newPosition1)
        {
            newPosition1 = Random.insideUnitSphere * radius;
        }
        if (sphere2.transform.localPosition == newPosition2)
        {
            newPosition2 = Random.insideUnitSphere * radius;
        }
        //if ((sphere1.transform.localPosition - sphere2.transform.localPosition).sqrMagnitude <= 4)
        //{//如果两个小球发生碰撞
        //    newPosition1 = -newPosition1;
        //    newPosition2 = -newPosition2;
        //}

        sphere1.transform.localPosition = Vector3.MoveTowards(sphere1.transform.localPosition, newPosition1, moveSpeed * Time.deltaTime);
        sphere2.transform.localPosition = Vector3.MoveTowards(sphere2.transform.localPosition, newPosition2, moveSpeed * Time.deltaTime);
    }

    void OnGUI()
    {
        GUI.Label(new Rect(100, 100, 200, 100), "<color=#00ff00><size=30>"+distance.ToString()+"</size></color>");
    }
}
