// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: contact.proto

#include "contact.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>

PROTOBUF_PRAGMA_INIT_SEG

namespace _pb = ::PROTOBUF_NAMESPACE_ID;
namespace _pbi = _pb::internal;

PROTOBUF_CONSTEXPR Contact::Contact(
    ::_pbi::ConstantInitialized): _impl_{
    /*decltype(_impl_.contact_type_)*/{}
  , /*decltype(_impl_._cached_size_)*/{}
  , /*decltype(_impl_._oneof_case_)*/{}} {}
struct ContactDefaultTypeInternal {
  PROTOBUF_CONSTEXPR ContactDefaultTypeInternal()
      : _instance(::_pbi::ConstantInitialized{}) {}
  ~ContactDefaultTypeInternal() {}
  union {
    Contact _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 ContactDefaultTypeInternal _Contact_default_instance_;
static ::_pb::Metadata file_level_metadata_contact_2eproto[1];
static constexpr ::_pb::EnumDescriptor const** file_level_enum_descriptors_contact_2eproto = nullptr;
static constexpr ::_pb::ServiceDescriptor const** file_level_service_descriptors_contact_2eproto = nullptr;

const uint32_t TableStruct_contact_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::Contact, _internal_metadata_),
  ~0u,  // no _extensions_
  PROTOBUF_FIELD_OFFSET(::Contact, _impl_._oneof_case_[0]),
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  ::_pbi::kInvalidFieldOffsetTag,
  ::_pbi::kInvalidFieldOffsetTag,
  PROTOBUF_FIELD_OFFSET(::Contact, _impl_.contact_type_),
};
static const ::_pbi::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, -1, sizeof(::Contact)},
};

static const ::_pb::Message* const file_default_instances[] = {
  &::_Contact_default_instance_._instance,
};

const char descriptor_table_protodef_contact_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\rcontact.proto\";\n\007Contact\022\017\n\005email\030\001 \001("
  "\tH\000\022\017\n\005phone\030\002 \001(\tH\000B\016\n\014contact_typeb\006pr"
  "oto3"
  ;
static ::_pbi::once_flag descriptor_table_contact_2eproto_once;
const ::_pbi::DescriptorTable descriptor_table_contact_2eproto = {
    false, false, 84, descriptor_table_protodef_contact_2eproto,
    "contact.proto",
    &descriptor_table_contact_2eproto_once, nullptr, 0, 1,
    schemas, file_default_instances, TableStruct_contact_2eproto::offsets,
    file_level_metadata_contact_2eproto, file_level_enum_descriptors_contact_2eproto,
    file_level_service_descriptors_contact_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK const ::_pbi::DescriptorTable* descriptor_table_contact_2eproto_getter() {
  return &descriptor_table_contact_2eproto;
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY2 static ::_pbi::AddDescriptorsRunner dynamic_init_dummy_contact_2eproto(&descriptor_table_contact_2eproto);

// ===================================================================

class Contact::_Internal {
 public:
};

Contact::Contact(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor(arena, is_message_owned);
  // @@protoc_insertion_point(arena_constructor:Contact)
}
Contact::Contact(const Contact& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  Contact* const _this = this; (void)_this;
  new (&_impl_) Impl_{
      decltype(_impl_.contact_type_){}
    , /*decltype(_impl_._cached_size_)*/{}
    , /*decltype(_impl_._oneof_case_)*/{}};

  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  clear_has_contact_type();
  switch (from.contact_type_case()) {
    case kEmail: {
      _this->_internal_set_email(from._internal_email());
      break;
    }
    case kPhone: {
      _this->_internal_set_phone(from._internal_phone());
      break;
    }
    case CONTACT_TYPE_NOT_SET: {
      break;
    }
  }
  // @@protoc_insertion_point(copy_constructor:Contact)
}

inline void Contact::SharedCtor(
    ::_pb::Arena* arena, bool is_message_owned) {
  (void)arena;
  (void)is_message_owned;
  new (&_impl_) Impl_{
      decltype(_impl_.contact_type_){}
    , /*decltype(_impl_._cached_size_)*/{}
    , /*decltype(_impl_._oneof_case_)*/{}
  };
  clear_has_contact_type();
}

Contact::~Contact() {
  // @@protoc_insertion_point(destructor:Contact)
  if (auto *arena = _internal_metadata_.DeleteReturnArena<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>()) {
  (void)arena;
    return;
  }
  SharedDtor();
}

inline void Contact::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  if (has_contact_type()) {
    clear_contact_type();
  }
}

void Contact::SetCachedSize(int size) const {
  _impl_._cached_size_.Set(size);
}

void Contact::clear_contact_type() {
// @@protoc_insertion_point(one_of_clear_start:Contact)
  switch (contact_type_case()) {
    case kEmail: {
      _impl_.contact_type_.email_.Destroy();
      break;
    }
    case kPhone: {
      _impl_.contact_type_.phone_.Destroy();
      break;
    }
    case CONTACT_TYPE_NOT_SET: {
      break;
    }
  }
  _impl_._oneof_case_[0] = CONTACT_TYPE_NOT_SET;
}


void Contact::Clear() {
// @@protoc_insertion_point(message_clear_start:Contact)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  clear_contact_type();
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* Contact::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::_pbi::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // string email = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 10)) {
          auto str = _internal_mutable_email();
          ptr = ::_pbi::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
          CHK_(::_pbi::VerifyUTF8(str, "Contact.email"));
        } else
          goto handle_unusual;
        continue;
      // string phone = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 18)) {
          auto str = _internal_mutable_phone();
          ptr = ::_pbi::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
          CHK_(::_pbi::VerifyUTF8(str, "Contact.phone"));
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

uint8_t* Contact::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:Contact)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // string email = 1;
  if (_internal_has_email()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_email().data(), static_cast<int>(this->_internal_email().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "Contact.email");
    target = stream->WriteStringMaybeAliased(
        1, this->_internal_email(), target);
  }

  // string phone = 2;
  if (_internal_has_phone()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_phone().data(), static_cast<int>(this->_internal_phone().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "Contact.phone");
    target = stream->WriteStringMaybeAliased(
        2, this->_internal_phone(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:Contact)
  return target;
}

size_t Contact::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:Contact)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  switch (contact_type_case()) {
    // string email = 1;
    case kEmail: {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
          this->_internal_email());
      break;
    }
    // string phone = 2;
    case kPhone: {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
          this->_internal_phone());
      break;
    }
    case CONTACT_TYPE_NOT_SET: {
      break;
    }
  }
  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData Contact::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSourceCheck,
    Contact::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*Contact::GetClassData() const { return &_class_data_; }


void Contact::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg) {
  auto* const _this = static_cast<Contact*>(&to_msg);
  auto& from = static_cast<const Contact&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:Contact)
  GOOGLE_DCHECK_NE(&from, _this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  switch (from.contact_type_case()) {
    case kEmail: {
      _this->_internal_set_email(from._internal_email());
      break;
    }
    case kPhone: {
      _this->_internal_set_phone(from._internal_phone());
      break;
    }
    case CONTACT_TYPE_NOT_SET: {
      break;
    }
  }
  _this->_internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void Contact::CopyFrom(const Contact& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:Contact)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Contact::IsInitialized() const {
  return true;
}

void Contact::InternalSwap(Contact* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  swap(_impl_.contact_type_, other->_impl_.contact_type_);
  swap(_impl_._oneof_case_[0], other->_impl_._oneof_case_[0]);
}

::PROTOBUF_NAMESPACE_ID::Metadata Contact::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_contact_2eproto_getter, &descriptor_table_contact_2eproto_once,
      file_level_metadata_contact_2eproto[0]);
}

// @@protoc_insertion_point(namespace_scope)
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::Contact*
Arena::CreateMaybeMessage< ::Contact >(Arena* arena) {
  return Arena::CreateMessageInternal< ::Contact >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
