using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class SphereControl : MonoBehaviour {

    public GameObject sphere;
    public Vector3 scale;
    public float radius = 1;
    public float radiusmin = 1;
    public float radiusmax = 3;
    public float time;
    private bool go = false;

	// Use this for initialization
	void Start () {
        
	}
	
	// Update is called once per frame
	void Update () {
        if (go && radius >= radiusmax)
            go = false;
        else if (!go && radius <= radiusmin)
            go = true;
        if (!go)
        {
            radius -= (radiusmax-radiusmin) / time;
        }
        else if (go)
        {
            radius += (radiusmax-radiusmin) / time;
        }
        scale = new Vector3(radius, radius, radius);
        sphere.transform.localScale = scale;
	}
}
