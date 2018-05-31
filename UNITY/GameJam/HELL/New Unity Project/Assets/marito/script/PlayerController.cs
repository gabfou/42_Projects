  using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

[RequireComponent(typeof(Rigidbody2D))]
public class PlayerController : Stopmoving {

	public	GameObject		GameManager;
	private	Game_Manager	GM;
	public float					maxSpeed = 1f;
	[HideInInspector] public bool	facingRight = false;

	[Space]
	public float		jumpPower = 10f;
	public float		jumpIdle = .3f;
	public float		jumpwait = .3f;
	public float		maxYVelocity = 8f;
	public float		minYVelocity = -6f;
	bool				canJump = true;

	[Space]
	public float		minSlideVelocity = 3f;

	[Space]
	public float		slimeVelocityIgnore = .5f;

	[Space]
	public AudioClip	ouchClip;
	public AudioClip	jumpClip;

	public int			life = 1;
	public float		invulnTime = 1f;
	bool				canOuch = true;
	bool				sliding = false;

	bool				istapping = false;
	public Collider2D	zonebam;
	float				timesincetapping;

	bool 				jumping;
	bool				grounded = true;
	public Vector3		groundPosition;
	public Vector2		groundSize;
	public AudioClip	run;
	
	new Rigidbody2D	rigidbody2D;
	CircleCollider2D	circleCollider2d;
	BoxCollider2D		boxCollider2d;
	// SpriteRenderer	spriteRenderer;
	Animator		anim;
	AudioSource		audiosource;

	GameObject pike;
	
	float			tmp;

	// Use this for initialization
	void Start () {
		pike = GameObject.Find("maritopike");
		if (LevelManagerScript.hell == false)
			pike.SetActive(false);
		// spriteRenderer = GetComponent< SpriteRenderer >();
		GM = GameManager.GetComponent<Game_Manager>();
		rigidbody2D = GetComponent< Rigidbody2D >();
		circleCollider2d = GetComponent< CircleCollider2D >();
		boxCollider2d = GetComponent< BoxCollider2D >();


		rigidbody2D.interpolation = RigidbodyInterpolation2D.Interpolate;
		anim = GetComponent< Animator >();
		audiosource = Camera.main.GetComponent< AudioSource >();
		transform.localScale = new Vector3(transform.localScale.x * -1, transform.localScale.y, transform.localScale.z);
		jumping = false;
		//Flip();
		// anim.SetBool("facingright", facingRight);
		anim.SetBool("jumping", jumping);
		anim.SetBool("grounded", grounded);
	}

	void FixedUpdate()
	{
		print("hell?" +LevelManagerScript.hell);
		if (GM.GameState) {
			if (life < 0)
				return ;
			
			float move;
			
			move = Input.GetAxisRaw("Horizontal");

			if (base.cannotmove == true)
				return ;

			// Tapping(move);

			GroundCheck();

			Move(move);

			// SlideCheck();

			// anim.SetFloat("vely", rigidbody2D.velocity.y);

			rigidbody2D.velocity = new Vector2(move * maxSpeed, Mathf.Clamp(rigidbody2D.velocity.y, minYVelocity, maxYVelocity));
		}
	}

	void Tapping(float move)
	{
		if (istapping)
		{
			move = transform.position.x - Camera.main.ScreenToWorldPoint(new Vector3(Input.mousePosition.x, Input.mousePosition.y, Camera.main.nearClipPlane)).x;
			if (!istapping && move > 0 && !facingRight)
				Flip();
			else if (!istapping && move < 0 && facingRight)
				Flip();

			timesincetapping += Time.deltaTime;
			if (timesincetapping > 0.3f)
			{
				istapping = false;
			}
			else if (timesincetapping > 0.2f)
				zonebam.gameObject.SetActive(false);
			else if (timesincetapping > 0.1f)
				zonebam.gameObject.SetActive(true);
		}
		if (!istapping && Input.GetKey(KeyCode.Mouse1))
		{
			istapping = true;
			timesincetapping = 0;
			anim.SetTrigger("istapping");
		}
	}

	void Move(float move)
	{
		// audio

		// if (grounded && audiosource.isPlaying == false && move != 0)
		// {
		// 	audiosource.loop = true;
		// 	audiosource.clip = run;
		// 	audiosource.Play();
		// }
		// else if (move == 0 && audiosource.clip == run)
		// 	audiosource.Stop();

		if (!istapping && move > 0 && !facingRight)
			Flip();
		else if (!istapping && move < 0 && facingRight)
			Flip();
		if (move != 0)
			anim.SetBool("moving", true);
		else
			anim.SetBool("moving", false);	
	}

	bool ungrounded = false;

	void GroundCheck()
	{
		RaycastHit2D[] results = new RaycastHit2D[10];
		int collisionNumber = Physics2D.BoxCastNonAlloc(transform.position + groundPosition, groundSize, 0, Vector2.down, results, .0f, 1 << LayerMask.NameToLayer("Ground"));
	//print(collisionNumber);
		grounded = collisionNumber != 0;

		if (grounded == false)
			ungrounded = true;
		if (ungrounded == true && grounded == true)
		{
			jumping = false;
			anim.SetBool("jumping", jumping);
			ungrounded = false;
		}
		//print("lAAAA 2");
		//print(grounded);
		anim.SetBool("grounded", grounded);
	}

	// void SlideCheck()
	// {
	// 	float arx = Mathf.Abs(rigidbody2D.velocity.x);
	// 	if (arx > minSlideVelocity && Input.GetKeyDown(KeyCode.DownArrow))
	// 		sliding = true;
	// 	if (arx < minSlideVelocity || !grounded)
	// 		sliding = false;
		
	// 	anim.SetBool("sliding", sliding);
	// }

	void Flip()
	{
		facingRight = !facingRight;
		// anim.SetBool("facingright", facingRight);
		transform.localScale = new Vector3(transform.localScale.x * -1, transform.localScale.y, transform.localScale.z);
		//spriteRenderer.flipX = facingRight;
	}

	IEnumerator restart()
	{
		AsyncOperation asyncLoad = SceneManager.LoadSceneAsync(SceneManager.GetActiveScene().name);
	
		while (!asyncLoad.isDone)
        {
            yield return null;
        }
	}

	void Die()
	{
		boxCollider2d.enabled = false;
		circleCollider2d.enabled = false;
		rigidbody2D.velocity = new Vector2(0, 0);
		rigidbody2D.AddForce(new Vector2(0, 50), ForceMode2D.Impulse);

		anim.SetTrigger("death");
		cannotmove = true;
		LevelManagerScript.hell = false;
		StartCoroutine(GameOver());
	}

	void ouch()
	{
		canOuch = false;
		StartCoroutine(ResetCanOuch());
		life--;
		if (life < 1)
			Die();
		else
		{
			// audiosource.PlayOneShot(ouchClip, .6f);
			// anim.SetTrigger("ouch");
		}
	}

	IEnumerator ResetCanOuch()
	{
		yield return new WaitForSeconds(invulnTime);
		canOuch = true;
	}

	IEnumerator JumpDelay()
	{
		canJump = false;
		yield return new WaitForSeconds(jumpIdle);
		canJump = true;
	}
		
	IEnumerator JumpProtec()
	{
			// Debug.Log("he protec");
		
		yield return new WaitForSeconds(2f);
			// Debug.Log("he protec");
		
		while (grounded == true && jumping == true)
		{
			// Debug.Log("he protec");
			jumping = false;
			anim.SetBool("jumping", jumping);
		}
	}

	IEnumerator JumpWait()
	{
		jumping = true;
		anim.SetBool("jumping", jumping);
		yield return new WaitForSeconds(jumpwait);
		rigidbody2D.AddForce(new Vector2(0, jumpPower), ForceMode2D.Impulse);
	}
	
	void Update () {
		if (GM.GameState) {
			if (life < 1)
				return ;
			if (base.cannotmove == true)
				return ;
			if (grounded && Input.GetKeyDown(KeyCode.Space) && canJump && !jumping)
			{
			//	print("laaaaaa");
				audiosource.PlayOneShot(jumpClip, .2f);
				StartCoroutine(JumpProtec());
				StartCoroutine(JumpWait());
			//	new WaitForSeconds(jumpwait);
			//	rigidbody2D.AddForce(new Vector2(0, jumpPower), ForceMode2D.Impulse);
				StartCoroutine(JumpDelay());
			}
		}
	}

	void OnCollisionEnter2D(Collision2D other)
	{
		// if (other.collider.tag == "Slime")
		// {
		// 	if (rigidbody2D.velocity.y < slimeVelocityIgnore)
		// 		rigidbody2D.velocity = new Vector2(rigidbody2D.velocity.x, 0);
		// }
		// print("colide");
		if (other.collider.tag == "OS")
		{
			Die();
			return ;
		}
	}

	IEnumerator win()
	{
		yield return new WaitForSeconds(2f);
		StartCoroutine(GM.NextScene());
	}


	void OnTriggerEnter2D(Collider2D other)
	{
		if (other.tag == "finish")
		{
			cannotmove = true;
			// rigidbody2D.velocity = new Vector2(0, 0);
			StartCoroutine(win());
			anim.SetTrigger("finish");
		}
		if (other.tag == "death")
		{
			Die();
			return ;
		}
		// if (other.tag == "OS")
		// {
		// 	life = 0;
		// 	Die();
		// 	return ;
		// }

		// if (canOuch && other.tag == "ouch")
		// 	ouch();
	}

	void OnDrawGizmos()
	{
		Gizmos.color = Color.red;
		Gizmos.DrawWireCube(transform.position + groundPosition, groundSize);
	}

	IEnumerator GameOver()
	{
		yield return new WaitForSeconds(2);
		if (LevelManagerScript.passe2 == false)
			GM.GameOver();
		else
			StartCoroutine(restart());
	}
}
