using System.Collections;
using System.Collections.Generic;
using UnityEngine;

[ExecuteInEditMode]
public class render_with_shader : MonoBehaviour
{
	public float		intensity;
	public float 		Intensitytache = 0;
	public float		zoom = 1;
	public float		strength;
	public float		speed;
	private Material	material;
	public Texture2D	distortionTexture;
	public Texture2D	tacheTexture;


 	// Creates a private material used to the effect
 	void Awake ()
 	{
		material = new Material( Shader.Find("Hidden/Distort") );
 	}
 
	// Postprocess the image
	void OnRenderImage (RenderTexture source, RenderTexture destination)
	{
		material.SetTexture("_DisplacementTex", distortionTexture);
		material.SetTexture("_TacheTex", tacheTexture);
 		material.SetFloat("_bwBlend", intensity);
		material.SetFloat("_Strength", strength);
		material.SetFloat("_Speed", speed);
		material.SetFloat("_Zoom", zoom);
		material.SetFloat("_Intensitytache", Intensitytache);
		material.SetVector("_CentrePoint", new Vector4(Camera.main.transform.position.x, Camera.main.transform.position.y, Camera.main.transform.position.z, 0));
 		Graphics.Blit (source, destination, material);
	}
}
