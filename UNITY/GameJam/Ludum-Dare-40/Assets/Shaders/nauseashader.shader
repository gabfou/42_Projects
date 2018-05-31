Shader "Hidden/Distort" {
	Properties {
		_MainTex ("Base (RGB)", 2D) = "white" {}
		_DisplacementTex ("Displacement", 2D) = "white" {}
		_bwBlend ("Black & White blend", Range (0, 1)) = 0
		_Zoom ("Zoom", Float) = 1
		_Speed ("Speed", Float) = 1
		_Strength ("Strength", Range(0, 1)) = 0
		_CentrePoint ("Centre", Vector) = (0, 0, 0, 0)
		_Intensitytache ("_Intensitytache", Float) = 0
	}
	SubShader {
		Pass {
			Name "distorsion"
			CGPROGRAM
			#pragma vertex vert_img
			#pragma fragment frag
			
			#include "UnityCG.cginc"
			
			sampler2D _MainTex;
			sampler2D _DisplacementTex;
			sampler2D _TacheTex;
			float _bwBlend;
			float _Strength;
			float _Zoom;
			float _Speed;
			float4 _CentrePoint;
			float _Intensitytache;
			
			float4 frag(v2f_img i) : COLOR {
				float4 n = tex2D(_DisplacementTex, (i.uv + _Time.x * _Speed) * _Zoom) * _bwBlend;
				float2 d = n.yz * 2 - 1;
				float2 uv = i.uv;
				uv += float2(0, d.y) * _Strength;
				float4 tachement = tex2D(_TacheTex, uv);
				uv = saturate(uv);
				n = tex2D(_MainTex, uv);

				// nawak rouge
				// tachement.x *= 3;
				// // tachement.x = 0;
				// n.x = n.x * (1 - tachement.x) + 130. / 256. * tachement.x;
				// n.y = n.y * (1 - tachement.x) + 70. / 256. * tachement.x;
				// n.z = n.z * (1 - tachement.x) + 42. / 256. * tachement.x;

				tachement.x = tachement.x - 1;
				tachement.x *= -_Intensitytache;
				// tachement.x *= _Intensitytache;
				// tachement.x = 0;
				n.x = n.x * (1 - tachement.x) + 65. / 256. * tachement.x;
				n.y = n.y * (1 - tachement.x) + 35. / 256. * tachement.x;
				n.z = n.z * (1 - tachement.x) + 21. / 256. * tachement.x;
				return n;
			}
			ENDCG
		}
	}
}
