using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using DG.Tweening;

public enum RotationMode
{
	PingPong,
	Loop,
	Free,
}

public class RotatingPlatform : MonoBehaviour
{
	public RotationMode	mode = RotationMode.Free;
	public Ease			ease = Ease.InOutQuint;

	public float	rotationDuration = 4f;
	public float	minRotation;
	public float	maxRotation;

	Vector3			startForward;
	Quaternion		startRotation;

	void RotatePingPongMin()
	{
		transform.DOLocalRotateQuaternion(startRotation * Quaternion.AngleAxis(minRotation, startForward), rotationDuration).OnComplete(() => RotatePingPongMax()).SetEase(ease);
	}
	
	void RotatePingPongMax()
	{
		transform.DOLocalRotateQuaternion(startRotation * Quaternion.AngleAxis(maxRotation, startForward), rotationDuration).OnComplete(() => RotatePingPongMin()).SetEase(ease);
	}

	void RotateLoop()
	{
		transform.rotation = startRotation * Quaternion.AngleAxis(minRotation, startForward);
		transform.DOLocalRotateQuaternion(startRotation * Quaternion.AngleAxis(maxRotation, startForward), rotationDuration).OnComplete(() => RotateLoop()).SetEase(ease);
	}

	void FullRotation()
	{
		transform.rotation = startRotation * Quaternion.AngleAxis(0, startForward);
		transform.DOLocalRotateQuaternion(startRotation * Quaternion.AngleAxis(180, startForward), rotationDuration).OnComplete(() => RotateLoop())
				.OnComplete(() => transform.DOLocalRotateQuaternion(startRotation * Quaternion.AngleAxis(360, startForward), rotationDuration))
				.SetLoops(-1)
				.SetEase(ease);
	}

	void Start()
	{
		startRotation = transform.rotation;
		startForward = transform.forward;
		switch (mode)
		{
			case RotationMode.Free:
				FullRotation();
				break;
			case RotationMode.Loop:
				RotateLoop();
				break;
			case RotationMode.PingPong:
				RotatePingPongMax();
				break;
		}
	}
}
