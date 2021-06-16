#lang racket/base

(require (only-in '#%foreign ctype-c->scheme)
         ffi/unsafe)

(provide gdracket-pre-init)

(define _godot-bool _bool)
(define-cpointer-type _godot-string)

#;
(define godot-string->string
  (let ()
    (define-godot godot-string-utf8 (_fun _pointer -> _pointer))
    (define-godot godot-char-string-get-data (_fun _pointer -> _string/utf-8))
    (compose
      godot-char-string-get-data
      godot-string-utf8)))

(define-cstruct _godot-gdnative-init-options
  ([in-editor               _godot-bool]
   [core-api-hash           _uint64]
   [editor-api-hash         _uint64]
   [no-api-hash             _uint64]
   [report-version-mismatch _pointer]
   [report-loading-error    _pointer]
   [gd-native-library       _pointer]
   [api-struct              _pointer]
   [active-library-path     _godot-string]))

(define (gdracket-pre-init raw-init-opts)
  (define raw->cpointer (ctype-c->scheme _pointer))
  (define cpointer->opts (ctype-c->scheme _godot-gdnative-init-options-pointer))
  (gdracket-init
    (cpointer->opts
      (raw->cpointer raw-init-opts))))

(define (gdracket-init init-opts)
  (displayln init-opts))

(display (banner))
(displayln "gdracket module loaded")

