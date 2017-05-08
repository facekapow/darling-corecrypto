#include <corecrypto/ccrsa.h>

int ccrsa_import_pub(ccrsa_pub_ctx_t key, size_t inlen, const uint8_t *der) {
}

cc_size ccder_decode_rsa_pub_n(const uint8_t *der, const uint8_t *der_end) {
}

int ccrsa_pub_crypt(ccrsa_pub_ctx_t key, cc_unit *out, const cc_unit *in) {
}

int ccrsa_generate_key(unsigned long nbits, ccrsa_full_ctx_t rsa_ctx,
                       size_t e_size, const void *e, struct ccrng_state *rng) {
}

int ccrsa_priv_crypt(ccrsa_priv_ctx_t key, cc_unit *out, const cc_unit *in) {
}

cc_size ccder_decode_rsa_priv_n(const uint8_t *der, const uint8_t *der_end) {
}

const uint8_t *ccder_decode_rsa_priv(const ccrsa_full_ctx_t key, const uint8_t *der, const uint8_t *der_end) {
}

int ccrsa_verify_pkcs1v15(ccrsa_pub_ctx_t key, const uint8_t *oid,
                          size_t digest_len, const uint8_t *digest,
                          size_t sig_len, const uint8_t *sig,
                          bool *valid) {
}

void ccrsa_init_pub(ccrsa_pub_ctx_t key, const cc_unit *modulus,
                    const cc_unit *e) {
}

CC_NONNULL_TU((2)) CC_NONNULL((4, 5, 6))
int
ccrsa_generate_fips186_key(unsigned long nbits, ccrsa_full_ctx_t fk,
                           size_t e_size, const void *eBytes,
                           struct ccrng_state *rng1, struct ccrng_state *rng2) {
}

CC_NONNULL_TU((1)) CC_NONNULL((3))
int ccrsa_export_pub(const ccrsa_pub_ctx_t key, size_t out_len, uint8_t *out) {
}

CC_NONNULL((1)) CC_NONNULL((2))
cc_size ccder_decode_rsa_pub_x509_n(const uint8_t *der, const uint8_t *der_end) {
}

CC_NONNULL_TU((1))
size_t ccder_encode_rsa_priv_size(const ccrsa_full_ctx_t key) {
}

CC_NONNULL_TU((1)) CC_NONNULL((2)) CC_NONNULL((3))
uint8_t *ccder_encode_rsa_priv(const ccrsa_full_ctx_t key, const uint8_t *der, uint8_t *der_end) {
}

CC_NONNULL_TU((1))
size_t ccder_encode_rsa_pub_size(const ccrsa_pub_ctx_t key) {
}

CC_NONNULL_TU((16)) CC_NONNULL((3, 5, 7, 9, 11, 13, 15))
int
ccrsa_make_fips186_key(unsigned long nbits,
                       const cc_size e_n, const cc_unit *e,
                       const cc_size xp1Len, const cc_unit *xp1, const cc_size xp2Len, const cc_unit *xp2,
                       const cc_size xpLen, const cc_unit *xp,
                       const cc_size xq1Len, const cc_unit *xq1, const cc_size xq2Len, const cc_unit *xq2,
                       const cc_size xqLen, const cc_unit *xq,
                       ccrsa_full_ctx_t fk,
                       cc_size *np, cc_unit *r_p,
                       cc_size *nq, cc_unit *r_q,
                       cc_size *nm, cc_unit *r_m,
                       cc_size *nd, cc_unit *r_d) {
}

CC_NONNULL_TU((1)) CC_NONNULL2
int ccrsa_get_pubkey_components(const ccrsa_pub_ctx_t pubkey, uint8_t *modulus, size_t *modulusLength, uint8_t *exponent, size_t *exponentLength) {
}

CC_NONNULL_TU((1)) CC_NONNULL2
int ccrsa_get_fullkey_components(const ccrsa_full_ctx_t key, uint8_t *modulus, size_t *modulusLength, uint8_t *exponent, size_t *exponentLength,
                                 uint8_t *p, size_t *pLength, uint8_t *q, size_t *qLength) {
}

CC_NONNULL_TU((1)) CC_NONNULL((2, 4, 5, 6))
int ccrsa_sign_pkcs1v15(ccrsa_full_ctx_t key, const uint8_t *oid,
                        size_t digest_len, const uint8_t *digest,
                        size_t *sig_len, uint8_t *sig) {
}
