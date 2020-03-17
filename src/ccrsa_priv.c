#include <corecrypto/ccrsa_priv.h>
#include <stdio.h>
#include <stdlib.h>
#include <corecrypto/ccder.h>

int ccrsa_oaep_encode_parameter(const struct ccdigest_info* di,
                                struct ccrng_state *rng,
                                size_t r_size, cc_unit *r,
                                size_t message_len, const uint8_t *message,
                                size_t parameter_data_len, const uint8_t *parameter_data)
{
	printf("DARLING CRYPTO STUB: %s\n", __PRETTY_FUNCTION__);
	return -1;
}

int ccrsa_oaep_decode_parameter(const struct ccdigest_info* di,
                                size_t *r_len, uint8_t *r,
                                size_t s_size, cc_unit *s,
                                size_t parameter_data_len, const uint8_t *parameter_data)
{
	printf("DARLING CRYPTO STUB: %s\n", __PRETTY_FUNCTION__);
	return -1;
}

int ccrsa_encrypt_eme_pkcs1v15(ccrsa_pub_ctx_t key,
                           struct ccrng_state *rng,
                           size_t *r_size, uint8_t *r,
                           size_t s_size, const uint8_t *s)
{
	printf("DARLING CRYPTO STUB: %s\n", __PRETTY_FUNCTION__);
	return -1;
}

int ccrsa_encrypt_oaep(ccrsa_pub_ctx_t key,
                   const struct ccdigest_info* di,
                   struct ccrng_state *rng,
                   size_t *r_size, uint8_t *r,
                   size_t s_size, uint8_t *s,
                   size_t parameter_data_len,
                   const uint8_t *parameter_data)
{
	printf("DARLING CRYPTO STUB: %s\n", __PRETTY_FUNCTION__);
	return -1;
}

int ccrsa_decrypt_eme_pkcs1v15(ccrsa_full_ctx_t key,
                           size_t *r_size, uint8_t *r,
                           size_t s_size, uint8_t *s)
{
	printf("DARLING CRYPTO STUB: %s\n", __PRETTY_FUNCTION__);
	return -1;
}

int ccrsa_decrypt_oaep(ccrsa_full_ctx_t key,
                   const struct ccdigest_info* di,
                   size_t *r_size, uint8_t *r,
                       size_t c_size, uint8_t *c,
                       size_t parameter_data_len,
                       const uint8_t *parameter_data)
{
	printf("DARLING CRYPTO STUB: %s\n", __PRETTY_FUNCTION__);
	return -1;
}

int ccrsa_crt_makekey(cczp_t zm, const cc_unit *e, cc_unit *d, cczp_t zp, cc_unit *dp, cc_unit *qinv, cczp_t zq, cc_unit *dq)
{
	printf("DARLING CRYPTO STUB: %s\n", __PRETTY_FUNCTION__);
	return -1;
}

int ccrsa_emsa_pkcs1v15_encode(size_t emlen, uint8_t* em, size_t dgstlen, const uint8_t* dgst, const uint8_t* oid) {
	// I'll be quoting specific steps from RFC 8017 Sec. 9.2

	// 1. Apply the hash function to the message M to produce a hash value H
	//
	// NOTE:
	// we don't have to hash it; `dgst` already contains the hash

	// 2. Encode the algorithm ID for the hash function and the hash
  //    value into an ASN.1 value of type DigestInfo
	//
	// we actually just calculate the sizes;
	// we generate the encoded DER structure later on
	size_t alg_info_seq_size = ccder_sizeof_oid(oid) + ccder_sizeof(CCDER_NULL, 0);
	size_t digest_info_seq_size = ccder_sizeof(CCDER_CONSTRUCTED_SEQUENCE, alg_info_seq_size) + ccder_sizeof_raw_octet_string(dgstlen);
	// this is a.k.a. `tLen`
	size_t digest_info_size = ccder_sizeof(CCDER_CONSTRUCTED_SEQUENCE, digest_info_seq_size);

	// 3. If emLen < tLen + 11, output "intended encoded message length
  //    too short" and stop.
	if (emlen < digest_info_size + 11)
		return -1;

	// 4. Generate an octet string PS consisting of emLen - tLen - 3
  //    octets with hexadecimal value 0xff
	uint8_t* ps = em + 2;
	size_t ps_len = emlen - digest_info_size - 3;
	for (size_t i = 0; i < ps_len; ++i)
		ps[i] = 0xff;

	// 5.  Concatenate PS, the DER encoding T, and other padding to form
	//     the encoded message EM as
	//        EM = 0x00 || 0x01 || PS || 0x00 || T
	em[0] = 0x00;
	em[1] = 0x01;
	ps[ps_len] = 0x00;

	// this is where we actually generate the DER structure and hash the message
	// we bake them directly into `em` to avoid unnecessary allocations
	uint8_t* digest_info = ps + ps_len + 1;
	uint8_t* digest_info_end = digest_info + digest_info_size;
	uint8_t* h = digest_info_end - dgstlen;

	memcpy(h, dgst, dgstlen);

	ccder_encode_tl(CCDER_CONSTRUCTED_SEQUENCE, digest_info_seq_size, digest_info,
		ccder_encode_tl(CCDER_CONSTRUCTED_SEQUENCE, alg_info_seq_size, digest_info,
			ccder_encode_oid(oid, digest_info,
			ccder_encode_tl(CCDER_NULL, 0, digest_info,
		ccder_encode_tl(CCDER_OCTET_STRING, dgstlen, digest_info, h)))));

	return 0;
}

// NOTE(@facekapow):
// why is this even here?
// according to RFC 8017 (and even the earlier RFC 3447, which 8017 replaces),
// EMSA-PKCS #1 v1.5 only implements an encoding algorithm; no verification algorithm is specified
// so... not sure why this is here...
int ccrsa_emsa_pkcs1v15_verify(size_t emlen, uint8_t *em,
		               size_t dgstlen, const uint8_t *dgst,
			       const uint8_t *oid)
{
	printf("DARLING CRYPTO STUB: %s\n", __PRETTY_FUNCTION__);
	return -1;
}

int ccrsa_eme_pkcs1v15_encode(struct ccrng_state *rng,
		size_t r_size, cc_unit *r, size_t s_size,
		const uint8_t *s)
{
	printf("DARLING CRYPTO STUB: %s\n", __PRETTY_FUNCTION__);
	return -1;
}

int ccrsa_eme_pkcs1v15_decode(size_t *r_size, uint8_t *r,
		size_t s_size, cc_unit *s)
{
	printf("DARLING CRYPTO STUB: %s\n", __PRETTY_FUNCTION__);
	return -1;
}
