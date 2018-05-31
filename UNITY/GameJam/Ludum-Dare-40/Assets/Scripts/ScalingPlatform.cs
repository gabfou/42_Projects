using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using DG.Tweening;

public class ScalingPlatform : MonoBehaviour
{
	public float	duration = 2;
	public Ease		ease;
	public Vector3	dstScale;

	Vector3			defaultScale;

	void Scale()
	{
		transform.DOScale(dstScale, duration / 2)
			.OnComplete(() => transform.DOScale(defaultScale, duration / 2)
				.OnComplete(Scale)
			).SetEase(ease);
	}

	void Start ()
	{
		defaultScale = transform.localScale;
		Scale();
	}
	void Update () {
		
	}
}
